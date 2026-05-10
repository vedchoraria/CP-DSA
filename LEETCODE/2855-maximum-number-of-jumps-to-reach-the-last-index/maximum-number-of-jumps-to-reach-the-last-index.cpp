class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int ans =0;
        if(n<=1) return 0;
        vector<int>dp(n,-1);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(dp[i] != -1 && abs(nums[j]-nums[i]) <= target)
                dp[j] = max(dp[j], dp[i] +1);
            }
        }
        return dp[n-1];
    }
};