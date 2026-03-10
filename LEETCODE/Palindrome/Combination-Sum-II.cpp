1class Solution {
2
3public:
4    void com(int i, int target, vector<int>& ans, vector<int>& a, vector<vector<int>>& res) {
5        if(target == 0) {
6            res.push_back(ans);
7            return;
8        }
9        
10        for(int j = i; j < a.size(); j++) {
11            // Skip duplicates
12            if(j > i && a[j] == a[j-1]) continue;
13            
14            // Early termination if remaining elements are too large
15            if(a[j] > target) break;
16            
17            ans.push_back(a[j]);
18            com(j+1, target - a[j], ans, a, res);
19            ans.pop_back();
20        }
21    }
22    
23    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
24        vector<vector<int>> res;
25        vector<int> ans;
26        sort(candidates.begin(), candidates.end());
27        com(0, target, ans, candidates, res);
28        return res;
29    }
30
31};