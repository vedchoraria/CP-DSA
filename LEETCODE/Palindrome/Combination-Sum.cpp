1class Solution {
2public:
3void com(int i, int target, vector<int>& ans, vector<int>& a, vector<vector<int>>& res){
4    int n = a.size();
5
6    if(i == n){
7        if(target == 0){
8            res.push_back(ans);
9            return;
10        }
11        else return;
12    }
13    if(a[i]<= target && i<n){
14        
15        ans.push_back(a[i]);
16        com(i,target-a[i],ans,a,res);
17        ans.pop_back();
18    }
19    com(i+1,target,ans,a,res);
20
21
22}
23    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
24        vector<vector<int>>res;
25        vector<int>ans;
26        int n = candidates.size();
27        com(0,target, ans, candidates , res);
28        return res;
29    }
30};