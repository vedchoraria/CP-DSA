class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0 , base = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            total += nums[i];
            base += i*nums[i];
        }
        int ans =base;
        for(int i = n-1;i>0;i--){
            base = base + total - n*nums[i];
            ans = max(ans , base);
        }
        return ans;
    }
};