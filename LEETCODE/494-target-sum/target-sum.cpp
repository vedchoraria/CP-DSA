class Solution {
public:
    int solve(int i, int n, vector<int>nums, vector<vector<int>>& dp, int target){
        if(i==n) return target == 0;

        if(dp[i][target] != -1) return dp[i][target];
        int take =0;
        if(target >= nums[i])
         take = solve(i+1,n,nums, dp, target - nums[i]);
        int nt = solve(i+1, n, nums, dp, target);

        return dp[i][target] = take + nt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        // P - N = target 
        // P + N = Total Sum
        // 2P = target + Total Sum;
        int sum =0;
        for(int i : nums) sum += i;
        // if total is odd then no soln 
        if((target+sum) & 1) return 0;
        //tying to find the subset whose sum would be p
        int p = (target + sum)/2;

        if(abs(target) > sum) return 0;

if((target + sum) < 0) return 0;

if((target + sum) & 1) return 0;

        vector<vector<int>>dp( n,vector<int>(p+1 , -1));
        return solve(0,n,nums,dp,p);
    }
};