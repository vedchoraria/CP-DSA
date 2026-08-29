class Solution {
    int fa[100001];
    int find(int nd){
        return fa[nd] = (fa[nd] == nd) ? nd : find(fa[nd]);
    }
    void unite(int a, int b){
        int pa = find(a), pb = find(b);
        fa[pa] = pb;
    }
public:
    vector<int> lexicographicallySmallestArray(vector<int>& v, int l) {
        int n = v.size();
        vector<pair<int,int>>pr(n);
        for(int i=0; i<n; i++) pr[i] = {v[i], i};
        sort(pr.begin(), pr.end());
        for(int i=0; i<n; i++) fa[i] = i;
        for(int i=1; i<n; i++){
            auto [pa, pb] = pr[i-1];
            auto [a, b] = pr[i];
            if(abs(a-pa) <= l) unite(b, pb);
        }
        map<int,multiset<int>>mp;
        for(int i=0; i<n; i++){
            mp[find(pr[i].second)].insert(pr[i].first);
        }
        sort(pr.begin(), pr.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        for(auto &[a, i]: pr){
            auto &ms = mp[find(i)];
            v[i] = *(ms.begin());
            ms.erase(ms.begin());
        }
        return v;
    }
};