
#define ll long long 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll n = nums.size();
        // This will not work because element can be 0, and 0/0 = not defined, see tc 2
        // for(ll i : nums) total *= i;
        // for(ll &i : nums) i = total/i;

        vector<ll>pref(n,1);
        vector<ll>suff(n,1);
        for(ll i =1;i<n;i++){
            pref[i] = pref[i-1]*nums[i-1];
        }
        for(ll i = n-2; i>=0;i--){
            suff[i] = suff[i+1]*nums[i+1];
        }
        vector<int>ans(n,1);
        for(ll i =0;i<n;i++){
            ans[i] = (int)pref[i]*suff[i];
        }

        return ans;
    }
};