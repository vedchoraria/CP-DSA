class Solution {
public:
int solve(vector<int>&dp, vector<int>&coins, int amount, int n){
    if(amount==0) return 0;
    else if(amount<0) return 1e9;

    if(dp[amount] != -1) return dp[amount];
    int coin =1e9;
    for(int i=n-1;i>=0;i--){
        //This cond will not be here, because lets say amt = 3, coin 2 , then it will just get a 1, and then sont get into loop
        // if(amount >= coins[i]){
        //     coin = min(coin,1+ solve(dp,coins,amount-coins[i],n));
        // }

        coin = min(coin,1+solve(dp,coins,amount-coins[i] ,n) );
    }
    return dp[amount] = coin;

}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int>dp(amount+1,-1);
        int ans = solve(dp,coins,amount,n);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};