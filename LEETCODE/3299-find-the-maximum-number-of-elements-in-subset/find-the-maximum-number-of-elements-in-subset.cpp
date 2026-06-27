using ll = long long;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int>cnt;
        for(int i : nums){cnt[i]++;}
        int ans = 1;
        if(cnt[1]%2 == 0){
            ans = max(ans, cnt[1]-1);
        }
        else ans = max(ans, cnt[1]);
        cnt.erase(1);
        for(auto[it, v ]: cnt){
            ll x = it;
            int res = 0;
            for(;cnt.contains(x) and cnt[x] > 1; x*=x){
                res+=2;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }
        return ans;
    }
};