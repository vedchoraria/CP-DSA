class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0 , right = 0;
        int ans = 0;
        unordered_map<int,int>mpp;
        for(right ; right<n; right++){
            mpp[nums[right]]++;
            while(mpp[ nums[right] ] > k){
                mpp[ nums[left] ]--;
                left++;
            }
            ans= max(ans, right-left+1);
        }
        return ans;
    }
};