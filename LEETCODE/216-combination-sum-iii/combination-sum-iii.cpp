class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>curr; vector<vector<int>>ans;
        backtrack(0,k,n, curr, ans , nums);
        return ans;
    }

    void backtrack(int i , int k , int &target , vector<int>&curr , vector<vector<int>>& ans , vector<int>nums){
        if(target == 0 && k == curr.size()){
            ans.push_back(curr);
            return;
        }
        if(target < 0) return;
        if(i == 9) return;
        curr.push_back(nums[i]); target -= nums[i];
        backtrack(i+1 , k , target , curr , ans , nums);
        curr.pop_back();  target += nums[i];
        backtrack(i+1 , k , target , curr , ans , nums);
    }
};