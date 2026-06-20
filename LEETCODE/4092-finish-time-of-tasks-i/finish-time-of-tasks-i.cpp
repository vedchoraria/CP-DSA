class Solution {
public:
long long solve(vector<long long>&dp , vector<vector<long long>>&adj, vector<int>& baseTime, int i){
    if(adj[i].size() == 0) return baseTime[i];

    if(dp[i] != -1) return dp[i];

    long long mi = LLONG_MAX;
    long long ma = 0;

    for(long long j =0; j < adj[i].size() ; j++){

        long long t = solve(dp,adj,baseTime, adj[i][j]);
        mi = min(mi, t);
        ma = max(ma,t);
    }

    return dp[i] = ma + (ma-mi) + baseTime[i];

} 
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<long long>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        vector<long long>dp(n,-1);
        return solve(dp,adj,baseTime,0);
    }
};