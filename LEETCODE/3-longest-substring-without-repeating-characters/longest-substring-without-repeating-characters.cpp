#define ll long long
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<ll,ll>prev;

        ll n = s.length();
        ll ans =0; ll l = 0;

        for(ll i =0; i<n; i++){
            int c = s[i];
            if(prev.find(c) == prev.end()) prev[c] = i;
            else if(prev[c] >= l) 
            { l = prev[c] + 1;
            prev[c] = i;
            }
            prev[c] = i;

            ans = max(ans, i-l+1);
        }
        return ans;
    }
};