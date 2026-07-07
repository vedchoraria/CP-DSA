class Solution {
public:
    long long sumAndMultiply(int n) {
        string t = to_string(n);
        long long x = 0;
        long long sum = 0;
        for(char c : t){
            if(c == '0') continue;
            x = x*10 + c-'0';
            sum += c-'0';
        }
        return 1LL*sum*x;
    }
};