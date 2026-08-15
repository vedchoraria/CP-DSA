class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int t = 0; int cnt  =0;
        for(int i : nums) {t ^= i; if(i!=0) cnt++;}

        if(cnt <=1 && t == 0) return 0;
        
        return (t == 0) ? nums.size()-1 : nums.size();
    }
};