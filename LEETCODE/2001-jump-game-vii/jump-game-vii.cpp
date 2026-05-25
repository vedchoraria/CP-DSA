class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        if(s.back() == '1') return false;
        int n = s.size();
        vector<bool>dp(n, 0);
        queue<int>q;
        q.push(n-1);
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            if(s[i] == '1') continue;
            while(!q.empty() && i + mx < q.front()) q.pop();
            if(!q.empty() && i + mn <= q.front() && q.front() <= i + mx ){
                dp[i] = 1;
                q.push(i);
            }
        }
        return dp[0];
    }
};