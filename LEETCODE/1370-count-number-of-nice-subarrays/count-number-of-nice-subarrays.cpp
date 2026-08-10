class Solution {
public:
int solve(vector<int>&nums , int k){
    int odd = 0;
        int left = 0;
        int ans =0;
        int n = nums.size();
        for(int right = 0; right < n; right++){
            if(nums[right] &1) odd++;
            while(k - odd < 0){
                if(nums[left] & 1) odd--;
                left++;
            }
            ans+= right-left + 1;
        }
        return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums,k-1);
    }
};