class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n);

        // poorer -> richer
        for (auto &e : richer) {
            int rich = e[0];
            int poor = e[1];

            adj[poor].push_back(rich);
            indegree[rich]++;
        }

        vector<int> topo;
        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){

            int u=q.front();
            q.pop();

            topo.push_back(u);

            for(int v:adj[u]){

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        vector<int> ans(n);

        for(int i=0;i<n;i++)
            ans[i]=i;

        // DP on DAG
        for(int i=n-1;i>=0;i--){

            int u=topo[i];

            for(int v:adj[u]){

                if(quiet[ans[v]]<quiet[ans[u]])
                    ans[u]=ans[v];
            }
        }

        return ans;
    }
};