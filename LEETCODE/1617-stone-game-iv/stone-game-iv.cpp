class Solution {
public:

// bool solve(int n) {
//     if (n == 0)
//         return false;

//     for (int j = 1; j * j <= n; j++) {
//         if (!solve(n - j * j))
//             return true;
//     }

//     return false;
// }
    bool winnerSquareGame(int n) {
        // return solve(n);

        vector<bool>dp(n+1,false);
        for(int i = 1; i <= n; i++){
            
            for(int j =1 ; j*j <= i;j++){
                if(!dp[i-j*j]) dp[i] = true;
            }
            
        }

        return dp[n];
    }
};