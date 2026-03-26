class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m * n < 2) return false;

        long long total_sum = 0;
        vector<long long> row_sums(m, 0);
        vector<long long> col_sums(n, 0);
        
        const int MAX_VAL = 100000;
        vector<int> min_r(MAX_VAL + 1, m);
        vector<int> max_r(MAX_VAL + 1, -1);
        vector<int> min_c(MAX_VAL + 1, n);
        vector<int> max_c(MAX_VAL + 1, -1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = grid[i][j];
                row_sums[i] += v;
                col_sums[j] += v;
                if (i < min_r[v]) min_r[v] = i;
                if (i > max_r[v]) max_r[v] = i;
                if (j < min_c[v]) min_c[v] = j;
                if (j > max_c[v]) max_c[v] = j;
            }
            total_sum += row_sums[i];
        }

        // Check Horizontal Cuts
        long long s1 = 0;
        for (int i = 0; i < m - 1; ++i) {
            s1 += row_sums[i];
            long long s2 = total_sum - s1;
            if (s1 == s2) return true;
            if (s1 > s2) {
                long long diff = s1 - s2;
                if (diff <= MAX_VAL) {
                    int v = (int)diff;
                    int h1 = i + 1, w1 = n;
                    if (h1 > 1 && w1 > 1) {
                        if (min_r[v] <= i) return true;
                    } else if (h1 == 1 && w1 > 1) {
                        if (grid[0][0] == v || grid[0][n - 1] == v) return true;
                    } else if (h1 > 1 && w1 == 1) {
                        if (grid[0][0] == v || grid[i][0] == v) return true;
                    }
                }
            } else {
                long long diff = s2 - s1;
                if (diff <= MAX_VAL) {
                    int v = (int)diff;
                    int h2 = m - 1 - i, w2 = n;
                    if (h2 > 1 && w2 > 1) {
                        if (max_r[v] >= i + 1) return true;
                    } else if (h2 == 1 && w2 > 1) {
                        if (grid[m - 1][0] == v || grid[m - 1][n - 1] == v) return true;
                    } else if (h2 > 1 && w2 == 1) {
                        if (grid[i + 1][0] == v || grid[m - 1][0] == v) return true;
                    }
                }
            }
        }

        // Check Vertical Cuts
        s1 = 0;
        for (int j = 0; j < n - 1; ++j) {
            s1 += col_sums[j];
            long long s2 = total_sum - s1;
            if (s1 == s2) return true;
            if (s1 > s2) {
                long long diff = s1 - s2;
                if (diff <= MAX_VAL) {
                    int v = (int)diff;
                    int h1 = m, w1 = j + 1;
                    if (h1 > 1 && w1 > 1) {
                        if (min_c[v] <= j) return true;
                    } else if (h1 == 1 && w1 > 1) {
                        if (grid[0][0] == v || grid[0][j] == v) return true;
                    } else if (h1 > 1 && w1 == 1) {
                        if (grid[0][0] == v || grid[m - 1][0] == v) return true;
                    }
                }
            } else {
                long long diff = s2 - s1;
                if (diff <= MAX_VAL) {
                    int v = (int)diff;
                    int h2 = m, w2 = n - 1 - j;
                    if (h2 > 1 && w2 > 1) {
                        if (max_c[v] >= j + 1) return true;
                    } else if (h2 == 1 && w2 > 1) {
                        if (grid[0][n - 1] == v || grid[0][j + 1] == v) return true;
                    } else if (h2 > 1 && w2 == 1) {
                        if (grid[0][n - 1] == v || grid[m - 1][n - 1] == v) return true;
                    }
                }
            }
        }

        return false;
    }
};