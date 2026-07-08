class Solution {
public:
long long mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        long long pow10[n+1];
        pow10[0]=1;
        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
        }
        vector<int>sum(n+1,0);
        vector<long long>x(n+1,0);
        vector<int>cnt(n+1,0);
        for(int i=0;i<n;i++){
            int d=s[i]-'0';
            sum[i+1]=sum[i]+d;
            if(d>0)x[i+1]=(10*x[i]+d)%mod;
            else x[i+1]=x[i];
            cnt[i+1]=cnt[i]+(d>0);
        }
        int m=queries.size();
        vector<int>res(m,0);
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1]+1;
            int len=cnt[r]-cnt[l];
            long long valx=(x[r]-x[l]*pow10[len]%mod+mod)%mod;
            long long vals=sum[r]-sum[l];
            res[i]=(valx*vals)%mod;
        }
        return res;
    }
};