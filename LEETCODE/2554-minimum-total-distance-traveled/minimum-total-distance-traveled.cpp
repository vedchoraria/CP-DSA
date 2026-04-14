#define ll long long
class Solution {
public:
ll solve(vector<int>&robot , vector<int>& pos , int i , int j , vector<vector<ll>>&dp){
    if(i == robot.size()) return 0;
    if(j == pos.size()) return 1e15;
    //1e9+1e9 = 2*1e9 > 1e10 sometimes....therefore no risk
    if(dp[i][j]!= -1) return dp[i][j];
    //take
    ll take = 1LL*abs(robot[i]-pos[j]) + solve(robot , pos , i+1 , j+1 , dp);
    ll notTake = solve(robot , pos , i ,j+1 ,dp);

    return dp[i][j] = min(take , notTake);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());
        vector<int>pos;
        for(auto it : factory){
            int a = it[0] , b = it[1];
            while(b--) pos.push_back(a);
        }
        int n = robot.size();
        int m = pos.size();
        vector<vector<ll>>dp(n, vector<ll>(m, -1));
        return solve(robot , pos , 0 , 0 , dp);

    }
};