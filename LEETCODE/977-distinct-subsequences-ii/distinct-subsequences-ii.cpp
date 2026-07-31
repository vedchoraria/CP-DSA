class Solution {
public:
long long MOD = 1e9+7;
    int distinctSubseqII(string s) {
        long long n = s.length();
        // dp to store the total no of valid subsequences
        // last to store the last occurence of an alphabet
        vector<long long>dp(n+1,0) , last(26,-1);
        dp[0] = 1;
        for(long long i = 1; i <= n; i++){
            dp[i] = 1LL*2*dp[i-1];
            char ch = s[i-1];
            if(last[ch - 'a'] != -1){
                long long j = last[ch-'a'];
                dp[i] = 1LL*(dp[i] - dp[j-1] + MOD)%MOD;
            }

            last[ch-'a'] = i;
        }
        // non empty subsequence not allowed 
        return (dp[n] - 1 + MOD)%MOD;
    }
};