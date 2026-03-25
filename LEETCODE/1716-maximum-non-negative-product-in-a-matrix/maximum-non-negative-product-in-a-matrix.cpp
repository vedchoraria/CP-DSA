class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dpmax(n, vector<long long>(m));
        vector<vector<long long>> dpmin(n, vector<long long>(m));

        dpmax[0][0] = dpmin[0][0] = grid[0][0];

        // First row
        for (int j = 1; j < m; j++) {
            dpmax[0][j] = dpmin[0][j] = dpmax[0][j-1] * grid[0][j];
        }

        // First column
        for (int i = 1; i < n; i++) {
            dpmax[i][0] = dpmin[i][0] = dpmax[i-1][0] * grid[i][0];
        }

        // Rest of grid
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                long long a = dpmax[i-1][j] * grid[i][j];
                long long b = dpmin[i-1][j] * grid[i][j];
                long long c = dpmax[i][j-1] * grid[i][j];
                long long d = dpmin[i][j-1] * grid[i][j];

                dpmax[i][j] = max({a, b, c, d});
                dpmin[i][j] = min({a, b, c, d});
            }
        }

        long long ans = dpmax[n-1][m-1];

        if (ans < 0) return -1;
        return ans % MOD;
    }
};