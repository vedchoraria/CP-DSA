class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n+1,0);

        for(int i = n-1;i>=0;i--){
            dp[i] = INT_MIN;
            int taken = 0;
            for(int j = 0;j<3;j++){
                if(i+j<n){
                    taken += arr[i+j];
                    dp[i] = max(dp[i], taken - dp[i+j+1]);
                }
            }
        }


        if(dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};