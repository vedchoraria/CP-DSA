1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        sort(nums1.begin(), nums1.end());
5        bool e = false, o = false;
6        for(auto &i: nums1){
7            if(i&1) o = true;
8            else e = true;
9        }
10        if((e && !o) || (o && !e)) return true;
11        // odd
12        return (nums1[0]%2 == 1);
13    }
14};