1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        int n = s.length();
5        vector<int> cnt;
6        int i = 1;
7        bool iszero = (s[0] == '0') ? true : false;
8        int temp = 1;
9        int prev = 0, ans = 0;
10        for (i; i < n; i++) {
11            if (s[i] == s[i - 1])
12                temp++;
13            else {
14                prev = temp;
15                temp = 1;
16            }
17
18            if (prev >= temp)
19                ans++;
20        }
21
22        return ans;
23    }
24
25    // int countBinarySubstrings(string s) {
26    //     int n = s.length();
27    //     vector<int> cnt;
28    //     int i = 1;
29    //     bool iszero = (s[0] == '0') ? true : false;
30    //     int temp = 1;
31    //     for (i; i < n; i++) {
32    //         if (s[i] == s[i - 1])
33    //             temp++;
34    //         else {
35    //             cnt.push_back(temp);
36    //             temp = 1;
37    //         }
38    //     }
39    //     cnt.push_back(temp);
40    //     int ans = 0;
41    //     for (int j = 1; j < cnt.size(); j++) {
42
43    //         ans += min(cnt[j], cnt[j - 1]);
44    //     }
45    //     return ans;
46    // }
47};