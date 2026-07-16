class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        int n = nums.size();
        vector<int>pref(n,1);
        pref[0] = nums[0];
        for(int i =1;i<n;i++){
            mx = max(mx, nums[i]);
            pref[i] = gcd(nums[i] , mx);
        }
        sort(pref.begin(), pref.end());
        long long ans = 0;
        int l =0 , h = n-1;
        while(l<h){
            ans += 1LL * gcd(pref[l] , pref[h]);
            l++; h--;
        }

        return ans;
    }
};