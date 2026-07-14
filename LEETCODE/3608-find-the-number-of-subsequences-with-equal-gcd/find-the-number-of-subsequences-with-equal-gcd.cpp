class Solution {
public:
long long int mod=1e9+7;
int solve(int i,int g1,int g2,int n,vector<int>&nums,vector<vector<vector<int>>>&dp){
    if(i==n){
        return (g1!=0)&&(g1==g2);
    }
    if(dp[i][g1][g2]!=-1)return dp[i][g1][g2];
    int ng1=gcd(g1,nums[i]);
    int ng2=gcd(g2,nums[i]);
    int cnt=solve(i+1,g1,g2,n,nums,dp)%mod;
    cnt=(cnt+solve(i+1,ng1,g2,n,nums,dp))%mod;
    cnt=(cnt+solve(i+1,g1,ng2,n,nums,dp))%mod;
    return dp[i][g1][g2]=cnt;
}
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int x=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(x+1,vector<int>(x+1,-1)));
        return solve(0,0,0,n,nums,dp);
    }
};