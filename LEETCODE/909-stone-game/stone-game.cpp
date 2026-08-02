class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // l to r 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i =0 ;i < n; i++) dp[i][i] = piles[i];

        for(int len = 2;len<=n;len++){
            for(int i = 0; i+len-1 < n ; i++){
                dp[i][i+len-1] = max(
                    piles[i] - dp[i+1][i+len-1], 
                    piles[i+len-1] - dp[i][i+len-2]
                );
            }
        } 

        return dp[0][n-1]>=0;
    }
};