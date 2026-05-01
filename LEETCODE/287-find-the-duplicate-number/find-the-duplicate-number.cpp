class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int left =0, right = nums.size()-1 , mid =0;
        while(left <= right){
            mid = left+(right-left)/2;
            if(mid >0 && nums[mid-1] == nums[mid])
            return nums[mid];
            else if(nums[mid] >mid) left = mid+1;
            else right = mid-1;
        }
        return nums[mid];
    }
};