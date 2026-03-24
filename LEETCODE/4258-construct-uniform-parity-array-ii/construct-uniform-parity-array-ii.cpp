class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        bool e = false, o = false;
        for(auto &i: nums1){
            if(i&1) o = true;
            else e = true;
        }
        if((e && !o) || (o && !e)) return true;
        // odd
        return (nums1[0]%2 == 1);
    }
};