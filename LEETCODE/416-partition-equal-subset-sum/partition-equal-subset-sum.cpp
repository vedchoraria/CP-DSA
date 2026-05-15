class Solution {
public:
bool solve(vector<vector<int>>&dp, int i, int sum ,int tot, vector<int>&nums){
    if(tot == (sum)) return true;
    if(i == nums.size()) return false;
    if(dp[i][sum] != -1) return dp[i][sum];

    int nt = solve(dp,i+1,sum,tot,nums);
    int t = false;
    if(tot>=(sum))
    t= solve(dp,i+1,sum+nums[i], tot, nums);
    return dp[i][sum] = (t||nt);
}
    bool canPartition(vector<int>& nums) {
        int total_Sum=0;
        int n = nums.size();

        for(int i : nums) total_Sum += i;
        if(total_Sum&1) return false;
        vector<vector<int>>dp(n,vector<int>(total_Sum+1,-1));
        return solve(dp,0,0,total_Sum/2, nums);
    }
};