class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        for(long long i = 3; i<16;i= i+3){
            long long x = pow(10,i);
            if(n<x) break;
            ans+= n-x+1;
        }
        return ans;
    }
};