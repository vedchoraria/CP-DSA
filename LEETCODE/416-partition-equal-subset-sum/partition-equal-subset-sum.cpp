class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(int x : nums)
            sum += x;

        // odd sum impossible
        if(sum % 2)
            return false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for(int num : nums){

            for(int s = target; s >= num; s--){

                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[target];
    }
};