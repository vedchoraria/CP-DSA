class Solution {
public:
static bool compare(vector<int>&a, vector<int>& b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
    int removeCoveredIntervals(vector<vector<int>>& it) {
        sort(it.begin(), it.end() , compare);
        int n = it.size(); vector<vector<int>>ans;
        ans.push_back(it[0]);
        for(int i = 1; i<n; i++){
            int start = ans.back()[0];
            int end = ans.back()[1];
            if (start <= it[i][0] and end >= it[i][1]) continue;
            else ans.push_back(it[i]);
        }
        return ans.size();
    }
};