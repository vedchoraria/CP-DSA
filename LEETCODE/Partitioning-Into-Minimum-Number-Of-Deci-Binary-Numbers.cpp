1class Solution {
2public:
3    int minPartitions(string n) {
4        int ma = 0;
5        for(char c: n){
6            if(c>ma+'0') ma = c-'0';
7        }
8        return ma;
9    }
10};