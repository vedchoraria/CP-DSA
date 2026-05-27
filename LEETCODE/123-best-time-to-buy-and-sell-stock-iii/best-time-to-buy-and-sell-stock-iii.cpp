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

class Solution {
public:
int solve(int index, int buy, int cap, vector<int>& prices , vector<vector<vector< int>>> &dp){
    int n = prices.size();
    if(index == n) return 0;

    if(cap == 0) return 0;

    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
    int profit =0;
    if(buy){
        int buyKaro = -prices[index] + solve(index+1, 0, cap, prices, dp);
        int skipKaro = 0 + solve(index+1, 1, cap, prices, dp);
        profit = max(buyKaro , skipKaro);
    }
    else{
        int sellKaro = prices[index] + solve(index+1, 1, cap-1 , prices, dp);
        int skipKaro = 0 + solve(index+1, 0, cap, prices, dp);
        profit = max(sellKaro , skipKaro);
    }
    return dp[index][buy][cap] = profit;
}
    int maxProfit(vector<int>& prices) {
        //index, buy, cap
        int n = prices.size();
        vector<vector<vector< int>>> dp(n,vector<vector<int>> ( 2 , vector<int> (3,-1) ) );
        return solve(0, 1, 2, prices,dp);
    }
};