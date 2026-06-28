class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n), ans;
        for(auto it : pre){
            int v = it[0], u = it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        if(indeg[i] == 0) q.push(i);

        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);

            for(int i : adj[u]){
                if(indeg[i] == 0) continue;
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }

        if(ans.size()!=n) return {};
        return ans;
    }
};