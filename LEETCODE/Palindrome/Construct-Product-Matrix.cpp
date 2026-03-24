1class Solution {
2public:
3    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
4        const int MOD = 12345;
5        int n = grid.size(), m = grid[0].size();
6        vector<vector<int>> p(n, vector<int>(m));
7
8        long long suffix = 1;
9        for (int i = n - 1; i >= 0; i--) {
10            for (int j = m - 1; j >= 0; j--) {
11                p[i][j] = suffix;
12                suffix = suffix * grid[i][j] % MOD;
13            }
14        }
15
16        long long prefix = 1;
17        for (int i = 0; i < n; i++) {
18            for (int j = 0; j < m; j++) {
19                p[i][j] = p[i][j] * prefix % MOD;
20                prefix = prefix * grid[i][j] % MOD;
21            }
22        }
23
24        return p;
25    }
26};