class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX, mx = 0;
        for(auto &i: nums){
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return 1ll*(mx-mn)*k;
    }
};