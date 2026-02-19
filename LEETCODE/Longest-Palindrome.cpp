1class Solution {
2public:
3    int longestPalindrome(string s) {
4        unordered_map<char,int>mpp;
5        for(char c: s){
6            mpp[c]++;
7        }
8        int ans =0;
9        bool one =false;
10        for(auto it : mpp){
11            int x = it.second;
12            ans += (2*(x/2));
13            if(x&1) one = true;
14        }
15        if(one)ans++;
16
17        return ans;
18    }
19};