// class Solution {
// public:
// int solve(int index, int buy, int cap, vector<int>& prices){
//     int n = prices.size();
//     if(index == n) return 0;

//     if(cap == 0) return 0;
//     int profit =0;
//     if(buy){
//         int buyKaro = -prices[index] + solve(index+1, 0, cap, prices);
//         int skipKaro = 0 + solve(index+1, 1, cap, prices);
//         profit = max(buyKaro , skipKaro);
//     }
//     else{
//         int sellKaro = prices[index] + solve(index+1, 1, cap-1 , prices);
//         int skipKaro = 0 + solve(index+1, 0, cap, prices);
//         profit = max(sellKaro , skipKaro);
//     }
//     return profit;
// }
//     int maxProfit(vector<int>& prices) {
//         return solve(0, 1, 2, prices);
//     }
// };

// class Solution {
// public:
// int solve(int index, int buy, int cap, vector<int>& prices ,
// vector<vector<vector< int>>> &dp){
//     int n = prices.size();
//     if(index == n) return 0;

//     if(cap == 0) return 0;

//     if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
//     int profit =0;
//     if(buy){
//         int buyKaro = -prices[index] + solve(index+1, 0, cap, prices, dp);
//         int skipKaro = 0 + solve(index+1, 1, cap, prices, dp);
//         profit = max(buyKaro , skipKaro);
//     }
//     else{
//         int sellKaro = prices[index] + solve(index+1, 1, cap-1 , prices, dp);
//         int skipKaro = 0 + solve(index+1, 0, cap, prices, dp);
//         profit = max(sellKaro , skipKaro);
//     }
//     return dp[index][buy][cap] = profit;
// }
//     int maxProfit(vector<int>& prices) {
//         //index, buy, cap
//         int n = prices.size();
//         vector<vector<vector< int>>> dp(n,vector<vector<int>> ( 2 ,
//         vector<int> (3,-1) ) ); return solve(0, 1, 2, prices,dp);
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // index, buy, cap
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(
//             n+1, vector<vector<int>>(2, vector<int>(3, 0)));
// // SIZE upgraded to n+1, with value 0 
//         for (int index = n - 1; index >= 0; index--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int cap = 2; cap > 0; cap--) {
//                     int profit = 0;
//                     if (buy) {
//                         int buyKaro = -prices[index] + dp[index+1][0][cap];
                                      
//                         int skipKaro = 0 + dp[index+1][1][cap]; 
//                         profit = max(buyKaro, skipKaro);
//                     } else {
//                         int sellKaro = prices[index] + dp[index+1][1][cap-1];
//                         int skipKaro = 0 + dp[index+1][0][cap]; 
//                         profit = max(sellKaro, skipKaro);
//                     }
//                     dp[index][buy][cap] = profit;
//                 }
//             }
//         }

//         return dp[0][1][2];
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // index, buy, cap

// int n = prices.size();
//         vector<vector<int>> prev (2, vector<int>(3, 0));
//         vector<vector<int>> curr (2, vector<int>(3, 0));

//         for (int index = n - 1; index >= 0; index--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int cap = 2; cap > 0; cap--) {
//                     int profit = 0;
//                     if (buy) {
//                         int buyKaro = -prices[index] + prev[0][cap];
                                      
//                         int skipKaro = 0 + prev[1][cap]; 
//                         profit = max(buyKaro, skipKaro);
//                     } else {
//                         int sellKaro = prices[index] + prev[1][cap-1];
//                         int skipKaro = 0 + prev[0][cap]; 
//                         profit = max(sellKaro, skipKaro);
//                     }
//                     curr[buy][cap] = profit;
//                 }
//             }

//             prev = curr;
//         }

//         return curr[1][2];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for (int i = 1; i < prices.size(); i++) {
            int price = prices[i];

            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);

            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};
