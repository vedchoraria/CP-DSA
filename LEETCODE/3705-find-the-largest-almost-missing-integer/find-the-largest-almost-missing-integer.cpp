class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
        if(k == n) return *max_element(nums.begin(), nums.end());
        unordered_map<int,int>mpp;
        for(int i : nums) mpp[i]++;
        bool start = false, end = false;
        if(mpp[nums[0]] == 1) start = true;
        if(mpp[nums[nums.size() - 1]] == 1) end = true;


        if(k == 1){
            int mx = -1;
            for(auto [x,y] : mpp){
                if(y == 1) mx = max(mx,x);
            }
            return mx;
        }
        if(start && end) return max(nums[0] , nums[nums.size() - 1]);
        else if(start) return nums[0];
        else if(end) return nums[nums.size()-1];
        else return -1;
    }
};