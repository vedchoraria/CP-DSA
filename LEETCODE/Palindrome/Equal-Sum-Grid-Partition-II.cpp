1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        if (m * n < 2) return false;
7
8        long long total_sum = 0;
9        vector<long long> row_sums(m, 0);
10        vector<long long> col_sums(n, 0);
11        
12        const int MAX_VAL = 100000;
13        vector<int> min_r(MAX_VAL + 1, m);
14        vector<int> max_r(MAX_VAL + 1, -1);
15        vector<int> min_c(MAX_VAL + 1, n);
16        vector<int> max_c(MAX_VAL + 1, -1);
17
18        for (int i = 0; i < m; ++i) {
19            for (int j = 0; j < n; ++j) {
20                int v = grid[i][j];
21                row_sums[i] += v;
22                col_sums[j] += v;
23                if (i < min_r[v]) min_r[v] = i;
24                if (i > max_r[v]) max_r[v] = i;
25                if (j < min_c[v]) min_c[v] = j;
26                if (j > max_c[v]) max_c[v] = j;
27            }
28            total_sum += row_sums[i];
29        }
30
31        // Check Horizontal Cuts
32        long long s1 = 0;
33        for (int i = 0; i < m - 1; ++i) {
34            s1 += row_sums[i];
35            long long s2 = total_sum - s1;
36            if (s1 == s2) return true;
37            if (s1 > s2) {
38                long long diff = s1 - s2;
39                if (diff <= MAX_VAL) {
40                    int v = (int)diff;
41                    int h1 = i + 1, w1 = n;
42                    if (h1 > 1 && w1 > 1) {
43                        if (min_r[v] <= i) return true;
44                    } else if (h1 == 1 && w1 > 1) {
45                        if (grid[0][0] == v || grid[0][n - 1] == v) return true;
46                    } else if (h1 > 1 && w1 == 1) {
47                        if (grid[0][0] == v || grid[i][0] == v) return true;
48                    }
49                }
50            } else {
51                long long diff = s2 - s1;
52                if (diff <= MAX_VAL) {
53                    int v = (int)diff;
54                    int h2 = m - 1 - i, w2 = n;
55                    if (h2 > 1 && w2 > 1) {
56                        if (max_r[v] >= i + 1) return true;
57                    } else if (h2 == 1 && w2 > 1) {
58                        if (grid[m - 1][0] == v || grid[m - 1][n - 1] == v) return true;
59                    } else if (h2 > 1 && w2 == 1) {
60                        if (grid[i + 1][0] == v || grid[m - 1][0] == v) return true;
61                    }
62                }
63            }
64        }
65
66        // Check Vertical Cuts
67        s1 = 0;
68        for (int j = 0; j < n - 1; ++j) {
69            s1 += col_sums[j];
70            long long s2 = total_sum - s1;
71            if (s1 == s2) return true;
72            if (s1 > s2) {
73                long long diff = s1 - s2;
74                if (diff <= MAX_VAL) {
75                    int v = (int)diff;
76                    int h1 = m, w1 = j + 1;
77                    if (h1 > 1 && w1 > 1) {
78                        if (min_c[v] <= j) return true;
79                    } else if (h1 == 1 && w1 > 1) {
80                        if (grid[0][0] == v || grid[0][j] == v) return true;
81                    } else if (h1 > 1 && w1 == 1) {
82                        if (grid[0][0] == v || grid[m - 1][0] == v) return true;
83                    }
84                }
85            } else {
86                long long diff = s2 - s1;
87                if (diff <= MAX_VAL) {
88                    int v = (int)diff;
89                    int h2 = m, w2 = n - 1 - j;
90                    if (h2 > 1 && w2 > 1) {
91                        if (max_c[v] >= j + 1) return true;
92                    } else if (h2 == 1 && w2 > 1) {
93                        if (grid[0][n - 1] == v || grid[0][j + 1] == v) return true;
94                    } else if (h2 > 1 && w2 == 1) {
95                        if (grid[0][n - 1] == v || grid[m - 1][n - 1] == v) return true;
96                    }
97                }
98            }
99        }
100
101        return false;
102    }
103};