class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++)
            mpp[arr[i]].push_back(i);
        queue<pair<int, int>> q;

        q.push({0, 0});
        vector<int> vis(n, 0);
        vis[0] = 1;
        while (!q.empty()) {
            auto it = q.front();
            int t = it.first;
            int steps = it.second;
            if (t == n - 1) {
                return steps;
            }
            q.pop();
            // left
            if (t - 1 >= 0 && !vis[t - 1]) {
                vis[t - 1] = 1;
                q.push({t - 1, steps + 1});
            }

            // right
            if (t + 1 < n && !vis[t + 1]) {
                vis[t + 1] = 1;
                q.push({t + 1, steps + 1});
            }

            vector<int> ab = mpp[arr[t]];
            for (int i = 0; i < ab.size(); i++) {
                if (!vis[ab[i]]) {
                    q.push({ab[i], steps + 1});
                    vis[ab[i]] = 1;
                }
            }

            // IMPORTANT optimization
            mpp[arr[t]].clear();
        }
        return -1;
    }
};