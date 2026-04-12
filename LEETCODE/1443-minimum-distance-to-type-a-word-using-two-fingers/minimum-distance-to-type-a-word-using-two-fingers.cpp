class Solution {
public:
    int dist(int a, int b) {
        if (a == 26 || b == 26) return 0;   // free initial position

        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();

        // dp[f1][f2] = minimum cost when finger1 at f1, finger2 at f2
        // 0-25 = A-Z, 26 = unused finger
        vector<vector<int>> dp(27, vector<int>(27, 1e9));
        dp[26][26] = 0;

        for (char ch : word) {
            int cur = ch - 'A';
            vector<vector<int>> ndp(27, vector<int>(27, 1e9));

            for (int f1 = 0; f1 <= 26; f1++) {
                for (int f2 = 0; f2 <= 26; f2++) {
                    if (dp[f1][f2] == 1e9) continue;

                    // Move finger1 to current letter
                    ndp[cur][f2] = min(ndp[cur][f2],
                                       dp[f1][f2] + dist(f1, cur));

                    // Move finger2 to current letter
                    ndp[f1][cur] = min(ndp[f1][cur],
                                       dp[f1][f2] + dist(f2, cur));
                }
            }

            dp = ndp;
        }

        int ans = 1e9;
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++) {
                ans = min(ans, dp[i][j]);
            }
        }

        return ans;
    }
};