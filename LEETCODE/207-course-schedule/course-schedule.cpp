class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // bi ---> ai
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto it : pre){
            int u = it[1]; int v = it[0];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        if(indeg[i] == 0)q.push(i);

        while(!q.empty()){
            int b = q.front();
            q.pop();

            for(int i : adj[b]){
                if(indeg[i] == 0) continue;
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        for(int i : indeg) if(i!=0) return false;
        return true;
        }
};