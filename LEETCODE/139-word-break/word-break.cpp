class Solution {
public:
int dp[300];
int help(int i , string s, set<string>& dic){
    if(i == s.size()) return 1;
    string temp;
    if(dp[i] != -1) return dp[i];

    dp[i] = 0;
    for(int j = i;j<s.size();j++){
        temp += s[j];
        if(dic.count(temp)){
            // found a word from j+1
            dp[i] = help(j+1,s,dic);
            if(dp[i]) return dp[i];
        }
    }

    return dp[i] = 0;
}
    bool wordBreak(string s, vector<string>& dic) {
        set<string>st ;
        for(auto a : dic) st.insert(a);
        memset(dp,-1,sizeof dp);
        return help(0,s,st);
    }
};