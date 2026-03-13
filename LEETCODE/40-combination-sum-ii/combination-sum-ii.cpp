class Solution {

public:
    void com(int i, int target, vector<int>& ans, vector<int>& a, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(ans);
            return;
        }
        
        for(int j = i; j < a.size(); j++) {
            // Skip duplicates
            if(j > i && a[j] == a[j-1]) continue;
            
            // Early termination if remaining elements are too large
            if(a[j] > target) break;
            
            ans.push_back(a[j]);
            com(j+1, target - a[j], ans, a, res);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        com(0, target, ans, candidates, res);
        return res;
    }

};