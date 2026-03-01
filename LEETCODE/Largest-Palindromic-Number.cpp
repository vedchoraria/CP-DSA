1class Solution {
2public:
3    string largestPalindromic(string num) {
4        vector<int> v(10, 0);
5        for (char c : num) {
6            v[c - '0']++;
7        }
8        string start = "";
9        string c = "";
10        bool one = false;
11
12        for (int i = 9; i >= 0; i--) {
13            cout<<start<<endl;
14            if(start.empty() && i==0) continue;
15            int n = v[i] / 2;
16            while (n--)
17                start += i + '0';
18
19            if (!one && (v[i] & 1)) {
20                one = true;
21                c += i + '0';
22            }
23        }
24        
25        if(!one && start.empty()) return "0";
26        
27
28        string end = start;
29        reverse(end.begin(), end.end());
30        return start + c + end;
31    }
32};