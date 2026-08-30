class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int mi_index = 0, ma_index=0;
        for(int i =1;i<n;i++){
            if(nums[i] > nums[ma_index]) ma_index = i;
            if(nums[i] < nums[mi_index]) mi_index = i;

        }
        int ans = n;
        // Case 1 : both from 1 end , n-
        ans = min(ans, max(n-ma_index, n-mi_index));
        // c2 both from right end
        ans = min(ans, max(ma_index+1, mi_index+1));
        // c3 : from left 1 and from right 1
        if(mi_index>ma_index) swap(mi_index, ma_index);

        ans = min(ans, mi_index+1 + n-ma_index);
        return ans;
    }
};