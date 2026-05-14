class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // First row
        for(int j=0; j<n; j++)
            dp[0][j] = matrix[0][j];

        // Build DP
        for(int row=1; row<n; row++) {

            for(int col=0; col<n; col++) {

                int temp = dp[row-1][col];

                // upper-left
                if(col > 0)
                    temp = min(temp,
                               dp[row-1][col-1]);

                // upper-right
                if(col < n-1)
                    temp = min(temp,
                               dp[row-1][col+1]);

                dp[row][col] =
                    matrix[row][col] + temp;
            }
        }

        // Final answer
        int ans = 1e9;

        for(int j=0; j<n; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};