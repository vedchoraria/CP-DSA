1class Solution {
2public:
3    long long combinationSum4(vector<int>& nums, int target) {
4        vector<long long> dp(target + 1, 0);
5        dp[0] = 1;
6
7        for(int t = 1; t <= target; t++){
8            for(int num : nums){
9                if(num <= t)
10                    dp[t] += dp[t - num];
11            }
12        }
13
14        return dp[target];
15    }
16};