class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>>ans;
        sort(it.begin(), it.end());
        ans.push_back(it[0]);
        
        int n = it.size();
        for(int i =1;i<n;i++){
            int start = ans.back()[0];
            int end = ans.back()[1];
            // ALL CASES
            // start <it[i][0] < it[i][1]< end complete overlap ignore
            // start < end < it[i][0]<it[i][1] add it 

            // sure shot start < it[i][0]<end<it[i][1] , end
            if(it[i][0] <= end) {
                ans.back()[1] = max(ans.back()[1], it[i][1]);
            }
            else{
                ans.push_back(it[i]);
            }
        }
        return ans;
    }
};