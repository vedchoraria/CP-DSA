class Solution {
    int recurse(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(j== -1) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = 0;
        if(s[i] == t[j]){
            cnt += recurse(i-1, j-1, s, t, dp);
            cnt += recurse(i-1, j, s, t, dp);
        }else{
            cnt += recurse(i-1, j, s, t, dp);
        }
        return dp[i][j] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return recurse(m-1, n-1, s, t, dp);
    }
};