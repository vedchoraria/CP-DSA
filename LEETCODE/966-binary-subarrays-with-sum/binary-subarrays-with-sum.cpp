class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>freq;
        int n = nums.size();
        int sum =0;
        int ans = 0;
        freq[0] = 1;
        for(int right = 0;right < n; right++){
            sum += nums[right];
            
            int need = sum - goal;
            ans += freq[need];
            freq[sum]++;
        }
        return ans;
    }
};