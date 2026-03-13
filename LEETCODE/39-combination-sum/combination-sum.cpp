// class Solution {
// public:
// void com(int i, int target, vector<int>& ans, vector<int>& a, vector<vector<int>>& res){
//     int n = a.size();

//     if(i == n){
//         if(target == 0){
//             res.push_back(ans);
//             return;
//         }
//         else return;
//     }
//     if(a[i]<= target && i<n){
        
//         ans.push_back(a[i]);
//         com(i,target-a[i],ans,a,res);
//         ans.pop_back();
//     }
//     com(i+1,target,ans,a,res);


// }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>>res;
//         vector<int>ans;
//         int n = candidates.size();
//         com(0,target, ans, candidates , res);
//         return res;
//     }
// };


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0].push_back(vector<int>()); // base

        for (int c : candidates) {
            for (int t = c; t <= target; ++t) {
                for (auto &comb : dp[t - c]) {
                    vector<int> newComb = comb;
                    newComb.push_back(c);
                    dp[t].push_back(newComb);
                }
            }
        }
        return dp[target];
    }
};