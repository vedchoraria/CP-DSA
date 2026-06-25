class Solution {
public:
    vector<vector<int>> adj;
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        // 2 removals
        // 1. Remove the useless leave nodes, i.e. they have no where to go and
        // they have 0 coins
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> deg(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            deg[u] = 0;
            for (int v : adj[u]) {
                if (deg[v] == 0)
                    continue;
                deg[v]--;
                if (deg[v] == 1 && coins[v] == 0)
                    q.push(v);
            }
        }
        queue<int> q2;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1)
                q2.push(i);
        }

        for (int round = 0; round < 2; round++) {

            int sz = q2.size();

            while (sz--) {

                int u = q2.front();
                q2.pop();

                deg[u] = 0;

                for (int v : adj[u]) {

                    if (deg[v] == 0)
                        continue;

                    deg[v]--;

                    if (deg[v] == 1)
                        q2.push(v);
                }
            }
        }

        int ans = 0;
        for (int i : deg)
            ans += i;
        return ans;
    }
};