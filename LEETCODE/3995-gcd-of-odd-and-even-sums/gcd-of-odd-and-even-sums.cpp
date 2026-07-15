class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }

    int gcd(int a ,int b){
        return (b == 0) ? a : gcd(b, a%b);
    }
};