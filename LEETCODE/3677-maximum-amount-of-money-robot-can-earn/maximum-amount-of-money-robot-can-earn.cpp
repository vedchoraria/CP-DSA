class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        //RECURSION
        // return helper(coins , 0 , 0 , 2);

        // RECURSIon + Memoization 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return helper(dp , coins , 0 , 0 , 2);
    }
    int helper(vector<vector<vector<int>>> &dp, vector<vector<int>>& coins , int i , int j , int skips){

        
        int n = coins.size();
        int m = coins[0].size();
            // Base Case
        if(i>=n || j>=m) return -1e7;
        if(i == n-1 && j == m-1){
            if(coins[i][j] < 0 && skips > 0) return 0;
            return coins[i][j];
        }


        if(dp[i][j][skips] != -1e9) return dp[i][j][skips];


        // right
        int right = helper(dp , coins , i , j+1 , skips) + coins[i][j];
        int down = helper(dp , coins , i+1 , j , skips) + coins[i][j];
        int take = max(right , down);
        int skip = -1e6;
        if(coins[i][j] < 0 && skips > 0){
            skip = max(
                helper(dp , coins , i , j+1 , skips-1) , 
                helper(dp , coins , i+1 , j , skips-1)
            );
        }

        return dp[i][j][skips] = max(take , skip);
    }

    // int helper(vector<vector<int>>& coins , int i , int j , int skips){
    //     int n = coins.size();
    //     int m = coins[0].size();

    //     // Base Case
    //     if(i>=n || j>=m) return -1e7;

    //     if(i == n-1 && j == m-1){
    //         if(coins[i][j] < 0 && skips > 0) return 0;
    //         return coins[i][j];
    //     }

    //     //right
    //     int right = helper(coins , i , j+1 , skips) + coins[i][j];
    //     int down = helper(coins , i+1 , j , skips) + coins[i][j];
    //     int take = max(right , down);
    //     int skip = -1e6;
    //     if(coins[i][j] < 0 && skips > 0){
    //         skip = max(
    //             helper(coins , i , j+1 , skips-1) , 
    //             helper(coins , i+1 , j , skips-1)
    //         );
    //     }

    //     return max(take , skip);
    // }

    
};