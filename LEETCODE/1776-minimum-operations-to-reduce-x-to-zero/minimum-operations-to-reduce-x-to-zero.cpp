class Solution {
    using ll = long long;
public:
    int minOperations(vector<int>& v, int xx) {
        int mn = 1e7, n = v.size();
        ll s = 0, x = xx;
        int l = 0;
        for(int i=0; i<n; i++){
            if(s + v[i] == x){
                s = x;
                l = i;
                break;
            }else if(s > x) break;
            s += v[i];
            l = i;
        }
        if(s < x) return -1;
        int r = n;
        while(l >= -1 && r > 0){
            if(s == x){
                mn = min(mn, l+1+n-r);
                if(l>=0){
                    s -= v[l];
                    l--;
                }else break;
            }else if(s < x){
                r--;
                s += v[r];
            }else{
                if(l>=0){
                    s -= v[l];
                    l--;
                }else break;
            }
        }
        if(mn == 1e7) mn = -1;
        return mn;
    }
};