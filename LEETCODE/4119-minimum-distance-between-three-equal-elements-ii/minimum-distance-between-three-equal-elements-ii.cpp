class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>vec(n+1);
        for(int i =0;i<n;i++){
            vec[nums[i]].push_back(i);      
        
        }


        int ans =INT_MAX;
        for(auto it : vec){
            int m = it.size();
            // for(int i : it) cout<<i<<" ";
            // cout<<endl;
            for(int i =2;i<m;i++){
                ans = min(ans , 2*(it[i]-it[i-2]));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};