1class Solution {
2public:
3    int minOperations(string s) {
4        bool zero = false;
5        int n = s.length();
6        int temp1 = 0;
7        for(int i =0;i<n;i++){
8            if (!((zero && s[i] == '0') || (!zero && s[i] == '1'))){
9                temp1++;
10            }
11            zero = !zero;
12        }
13        int temp2 = 0; zero = true;
14        for(int i =0;i<n;i++){
15            if (!((zero && s[i] == '0') || (!zero && s[i] == '1'))){
16                temp2++;
17            }
18            zero = !zero;
19        }
20
21        return min(temp1 , temp2);
22    }
23};