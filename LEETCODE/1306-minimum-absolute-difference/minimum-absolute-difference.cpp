class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // 1 2 3 4
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        int mi = INT_MAX;
        for(int i =1;i<arr.size();i++){
            int t = arr[i] - arr[i-1];
            mi = min(t,mi);
        }

        for(int i = 1; i<arr.size() ; i++){
            if( arr[i] - arr[i-1] == mi) ans.push_back({arr[i-1], arr[i]});
        }
        return ans;
    }
};