class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0]; int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);
        int ans = 0;
        for(int i =0; i<n; i++){
            if(vis[i] != 0) continue;
            int edges = 0;
            int sz = 0;
            queue<int>q;
            q.push(i); vis[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                vis[u]= 1;
                sz++;
                for(int v : adj[u]){
                    edges++;
                    if(vis[v] == 0){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
            cout<<edges << " "<<sz << endl;
            if(sz*(sz-1) == edges) ans ++;
        }

        return ans;
    }
};