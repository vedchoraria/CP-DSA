class Solution {
    int LOG;
    vector<vector<int>> dp;
    void dfs(int node, int par, vector<int> adj[]) {
        dp[node][0] = par;
        for(int i = 1; i < (int)dp[0].size(); i++)
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        for(auto it : adj[node]) {
            if(it == par) continue;
            dfs(it, node, adj);
        }
    }

    int getKpar(int node, int k) {
        for(int i = (int)dp[0].size() - 1; i >= 0; i--)
            if((k >> i) & 1)
                node = dp[node][i];
        return node;
    }

public:
    vector<int> pathExistenceQueries(int n, vector<int>& va, int md, vector<vector<int>>& qu) {
        LOG = __lg(n) + 1;
        vector<int> adj[n];
        vector<pair<int,int>>pr(n);
        for(int i=0; i<n; i++) pr[i] = {va[i], i};
        sort(pr.begin(), pr.end());
        for(int i=0; i<n; i++){
            auto [val, nd] = pr[i];
            int l = i, r = n, mid;
            while(r-l>1){
                mid = (l+r)/2;
                auto [dst, dn] = pr[mid];
                if(dst-val <= md) l = mid;
                else r = mid;
            }
            if(l == i) continue;
            adj[nd].push_back(pr[l].second);
            adj[pr[l].second].push_back(nd);
        }
        dp.assign(n + 1, vector<int>(LOG + 1, n));
        vector<int>comp(n, -1);
        int c = 0, prev = pr[0].first, prnd = pr[0].second;
        for(int i=0; i<n; i++){
            auto [val, nd] = pr[i];
            if(val-prev <= md) comp[nd] = c;
            else{
                dfs(prnd, prnd, adj);
                comp[nd] = ++c;
            } 
            prev = val;
            prnd = nd;
        }
        dfs(prnd, prnd, adj);
        vector<int>ans(qu.size());
        for(int i=0; i<qu.size(); i++){
            int u = qu[i][0], v = qu[i][1];
            if(u == v){
                ans[i] = 0; continue;
            }
            if(va[u] > va[v]) swap(u, v);
            int l = 0, r = n, mid;
            while(r-l>1){
                mid = (l+r)/2;
                if(va[getKpar(u, mid)] >= va[v]) r = mid;
                else l = mid;
            }
            if(r == n) r = -1;
            ans[i] = r;
        }
        return ans;
    }
};