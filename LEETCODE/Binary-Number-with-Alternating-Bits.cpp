1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        bool hasOne = (n&1)? true : false;
5        while(n>0){
6            if(hasOne && n&1) n = n>>1;
7            else if(!hasOne && !(n&1)) n = n>>1;
8            else return false;
9            hasOne = !hasOne;
10        }
11        return true;
12    }
13};