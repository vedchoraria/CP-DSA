const int inf = INT_MAX;
class Solution {
    int n;
    int dp[100005];
    int v[100005], pfx[100005];
    int f(int i){
        if(i == n-1){
            return pfx[n-1];
        }
        int &ans = dp[i];
        if(ans != inf) return ans;
        ans = max(f(i+1), pfx[i] - f(i+1));
        return ans;
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        // one main obs, pfx sum is the prev node value ( no need to maintain that)
        n = stones.size();
        v[0] = pfx[0] = stones[0];
        for(int i=1; i<n; i++){
            v[i] = stones[i];
            pfx[i] = v[i] + pfx[i-1];
        }
        for(int i=0; i<=n; i++){
            dp[i] = inf;
        }
        return f(1);
    }
};