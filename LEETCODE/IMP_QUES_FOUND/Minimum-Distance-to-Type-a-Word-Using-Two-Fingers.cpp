1class Solution {
2public:
3    int dist(int a, int b) {
4        if (a == 26 || b == 26) return 0;   // free initial position
5
6        int x1 = a / 6, y1 = a % 6;
7        int x2 = b / 6, y2 = b % 6;
8
9        return abs(x1 - x2) + abs(y1 - y2);
10    }
11
12    int minimumDistance(string word) {
13        int n = word.size();
14
15        // dp[f1][f2] = minimum cost when finger1 at f1, finger2 at f2
16        // 0-25 = A-Z, 26 = unused finger
17        vector<vector<int>> dp(27, vector<int>(27, 1e9));
18        dp[26][26] = 0;
19
20        for (char ch : word) {
21            int cur = ch - 'A';
22            vector<vector<int>> ndp(27, vector<int>(27, 1e9));
23
24            for (int f1 = 0; f1 <= 26; f1++) {
25                for (int f2 = 0; f2 <= 26; f2++) {
26                    if (dp[f1][f2] == 1e9) continue;
27
28                    // Move finger1 to current letter
29                    ndp[cur][f2] = min(ndp[cur][f2],
30                                       dp[f1][f2] + dist(f1, cur));
31
32                    // Move finger2 to current letter
33                    ndp[f1][cur] = min(ndp[f1][cur],
34                                       dp[f1][f2] + dist(f2, cur));
35                }
36            }
37
38            dp = ndp;
39        }
40
41        int ans = 1e9;
42        for (int i = 0; i <= 26; i++) {
43            for (int j = 0; j <= 26; j++) {
44                ans = min(ans, dp[i][j]);
45            }
46        }
47
48        return ans;
49    }
50};