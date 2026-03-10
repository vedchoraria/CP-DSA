1class Solution {
2public:
3    int combinationSum4(vector<int>& nums, int target) {
4
5        vector<unsigned int> dp(target + 1, 0);
6        dp[0] = 1;
7
8        for(int t = 1; t <= target; t++){
9            for(int num : nums){
10                if(num <= t){
11                    dp[t] += dp[t - num];
12                }
13            }
14        }
15
16        return dp[target];
17    }
18};