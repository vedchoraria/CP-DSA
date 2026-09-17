class Solution {
public:
    int minSumOfLengths(vector<int>& v, int tar) {
        // dp[i] min len
        int n = v.size();
        vector<int>dp(n, 1e8);
        int ans = 1e8;
        if(v[0] == tar) dp[0] = 1;
        map<long long,int>mp;
        mp[v[0]] = 0;
        long long s = v[0];
        for(int i=1; i<n; i++){
            s += v[i];
            dp[i] = dp[i-1];
            long long rem = s-tar;
            if(mp.count(rem)){
                int j = mp[rem];
                int len = i-j;
                ans = min(ans, len+dp[j]);
                dp[i] = min(dp[i], len);
            }else if(rem == 0){
                dp[i] = min(dp[i], i+1);
            }
            mp[s] = i;
        }
        if(ans >= 1e8) ans = -1;
        return ans;
    }
};