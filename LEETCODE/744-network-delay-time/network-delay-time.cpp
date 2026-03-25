class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            for (auto [nbr, wt] : adj[node]) {
                if (time + wt < dist[nbr]) {
                    dist[nbr] = time + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};