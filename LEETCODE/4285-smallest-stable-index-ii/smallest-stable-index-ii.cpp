class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ma(n,0), mi(n,0);
        mi[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--)mi[i] = min(mi[i+1] , nums[i]);
        ma[0] = nums[0];
        for(int i =1;i<n;i++) ma[i] = max(ma[i-1], nums[i]);
        int i =0;
        while(i<n){
            if(ma[i] - mi[i] <= k) return i;
            i++;
        }
        return -1;
    }
};