1#define ll long long
2class Solution {
3public:
4    bool isPalindrome(int x) {
5        ll t = (ll)x;
6        ll y = 0;
7        while(t>0){
8            y = y*10 + t%10; t/=10;
9        }
10        return (y == (ll)x) ? true : false;
11    }
12};