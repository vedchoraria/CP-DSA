class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        int mid;
        while(l<=h){
            mid = (h-l)/2 + l;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else {
                h = mid-1;
            }
        }
        return -1;
    }
};