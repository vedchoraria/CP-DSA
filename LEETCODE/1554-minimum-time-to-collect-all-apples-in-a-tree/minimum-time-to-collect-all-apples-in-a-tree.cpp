class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        vector<int>deg(n,0);

        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        // cout<<1<<endl;
        queue<int>q;
        for(int i =1;i<n;i++){
            if(deg[i]==1 and !hasApple[i]) q.push(i);
        }
        while(!q.empty()){
            
            int u = q.front();
            cout<<u<<endl;
            q.pop();
            deg[u]=0;
            for(int v : adj[u]){
                
                if(deg[v] == 0) continue;
                deg[v]--;
                if(v==0) continue;
                if(deg[v] == 1 and !hasApple[v]) q.push(v);
            }
        }
        int ans =0;
        for(int i : deg) ans += i;
        return ans;
    }
};