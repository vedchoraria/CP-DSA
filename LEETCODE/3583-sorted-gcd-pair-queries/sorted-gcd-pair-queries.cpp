class Solution {
public:
    vector<int> gcdValues(vector<int>& v, vector<long long>& qu) {
        int mx = *max_element(v.begin(), v.end());
        using ll = long long;
        vector<ll>cnt(mx+1, 0), mult(mx+1, 0), f(mx+1);
        for(auto &i: v) f[i]++;
        for(int i=1; i<=mx; i++){
            for(int j=i; j<=mx; j += i){
                mult[i] += f[j];
            }
        }
        for(int i=1; i<=mx; i++){
            cnt[i] = mult[i]*(mult[i]-1)/2;
        }
        for(int i=mx; i>=1; i--){
            for(int j=i+i; j<=mx; j += i){
                cnt[i] -= cnt[j];
            }
        }
        // now pfx
        for(int i=2; i<=mx; i++){
            cnt[i] += cnt[i-1];
        }
        int sz = qu.size();
        vector<int>ans(sz);
        for(int i=0; i<sz; i++){
            ll l = 0, r = mx+1, mid, t = qu[i];
            while(r-l>1){
                mid = (l+r)/2;
                if(cnt[mid] <= t) l = mid;
                else r = mid;
            }
            ans[i] = r;
        }
        return ans;
    }
};