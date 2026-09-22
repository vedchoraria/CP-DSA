using ll = long long;
#define all(v) (v).begin(), (v).end()
template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<int> v; // type may change
    int k;
    int n;
    SegTree(int a_len, int kv, vector<int> &a) { // change if type updated
        v = a;
        k = kv;
        n = a_len;
        tree.resize(4 * n,  Node(k));
        build(0, n - 1, 1, k);
    }
    void build(int start, int end, int idx, int k)  // Never change this
    {
        if (start == end)	{
            tree[idx] = Node(v, start, end, k);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * idx, k);
        build(mid + 1, end, 2 * idx + 1, k);
        tree[idx].merge(v, tree[2 * idx], tree[2 * idx + 1]);
    }
    void update(int start, int end, int idx, int query_index, Update &u)  // Never Change this
    {
        if (start == end) {
            u.apply(tree[idx], k);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * idx, query_index, u);
        else
            update(mid + 1, end, 2 * idx + 1, query_index, u);
        tree[idx].merge(v, tree[2 * idx], tree[2 * idx + 1]);
    }
    Node query(int start, int end, int idx, int left, int right) { // Never change this
        if (start > right || end < left)
            return Node(k);
        if (start >= left && end <= right)
            return tree[idx];
        int mid = (start + end) / 2;
        Node l(k), r(k), ans(k);
        l = query(start, mid, 2 * idx, left, right);
        r = query(mid + 1, end, 2 * idx + 1, left, right);
        ans.merge(v, l, r);
        return ans;
    }
    void make_update(int idx, ll val) {  // pass in as many parameters as required
        v[idx] = val;
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, idx, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1 {
    int k;
    int st, en, prd;
    int pf[5];

    Node1(int kv) {
        k = kv;
        st = en = -1;
        prd = 1 % k;
        for(int i=0; i<k; i++) pf[i] = 0;
    }

    Node1(vector<int>& v, int stt, int enn, int kv) {
        k = kv;
        st = stt;
        en = enn;
        prd = v[st] % k;
        for(int i=0; i<k; i++) pf[i] = 0;
        pf[prd] = 1;
    }

    void merge(vector<int>& v, Node1 &l, Node1 &r) {

        if(l.st == -1) {
            *this = r;
            return;
        }

        if(r.st == -1) {
            *this = l;
            return;
        }
        prd = (1LL * l.prd * r.prd) % k;

        for(int i = 0; i < k; i++) {
            pf[i] = l.pf[i];
        }
        for(int i = 0; i < k; i++) {
            int id = (1LL * l.prd * i) % k;
            pf[id] += r.pf[i];
        }

        st = l.st;
        en = r.en;
    }
};
struct Update1 {
    ll val; // may change
    Update1(ll p1) { 
        val = p1; 
    }
    void apply(Node1 &a, int k) { // apply update to given node
       for(int i=0; i<k; i++) a.pf[i] = 0;
       a.pf[val%k] = 1;
       a.prd = val%k;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& v, int k, vector<vector<int>>& que) {
        int n = v.size();
        SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, k, v);
        int q = que.size();
        vector<int>ans(q);
        for(int i=0; i<q; i++){
            int id = que[i][0], val = que[i][1], st = que[i][2], x = que[i][3];
            seg.make_update(id, val);
            ans[i] = seg.make_query(st, n-1).pf[x];
        }
        return ans;
    }
};