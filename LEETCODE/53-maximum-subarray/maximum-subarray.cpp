class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, right = 1 , left = 0, n = nums.size();
        int sum =nums[0];
        for(int i : nums) ans = max(ans,i);
        for(right;right<n;right++){
            while(sum<0 && left<right){
                sum -= nums[left];
                left++;
            }
            sum += nums[right];
            ans = max(ans,sum);
        }
        return ans;
    }
};