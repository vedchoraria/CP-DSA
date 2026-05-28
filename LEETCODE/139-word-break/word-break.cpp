class Solution {
public:
//     bool solve(int i, unordered_map<string,int>&mpp, string &s, string temp, vector<int>&dp){
//         if(i < 0){
//     return mpp[temp];
// }
//     if(dp[i] != -1) return dp[i];
//         temp = s[i] + temp;
//         bool reduce = false;
//         if(mpp[temp])
//          reduce = solve(i-1, mpp,s,"", dp);

//         bool nreduce = solve(i-1,mpp,s,temp,dp);

//         return dp[i] = reduce||nreduce;

//     }
    bool wordBreak(string s, vector<string>& dic) {
        unordered_map<string,int>mpp;
        for(string i : dic) mpp[i] = 1;
        int n = s.size();
        vector<int>dp(n+1,0);
        // return solve(n-1, mpp,s,"", dp);
        dp[n] = true;
        for(int i = n-1;i>=0;i--){
            string temp = "";
            for(int j = i;j<n;j++){
                temp += s[j];
                if(mpp[temp] && dp[j+1])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};