class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0 || n == 1) return 1-n;
        int k = n-1;
        int p = log2(n+k); int ans;
        if(pow(2,p) == n) ans = n-1;
        else ans = pow(2,p)-1-n;
        return ans;
        }
};