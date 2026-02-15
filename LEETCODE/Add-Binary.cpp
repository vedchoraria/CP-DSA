1class Solution {
2public:
3    void helper(int& carry, int& sum) {
4        if (sum == 0) {
5            // cout<<"A :"<<endl;
6            carry = 0;
7            sum = 0;
8        } else if (sum == 1) {
9            carry = 0;
10            sum = 1;
11        } else if (sum == 2) {
12            carry = 1;
13            sum = 0;
14        } else if (sum == 3) {
15            carry = 1;
16            sum = 1;
17        } else{
18            carry = 0;
19            sum = 0;
20        }
21    }
22    string addBinary(string a, string b) {
23        string ans = "";
24        reverse(a.begin(), a.end());
25        reverse(b.begin(), b.end());
26
27        int n = a.length(), m = b.length();
28        int carry = 0;
29        int i = 0;
30        while (i < n && i < m) {
31            int sum = a[i]-'0' + b[i]-'0' + carry;
32            // cout<<sum<<endl;
33            helper(carry, sum);
34            i++;
35            // cout<<sum<<endl;
36            ans += sum + '0';
37        }
38        
39        while (i < n) {
40            int sum = a[i]-'0' + carry;
41            // cout<<sum<<endl;
42            helper(carry, sum);
43            i++;
44            ans += sum + '0';
45        }
46
47        while (i < m) {
48            int sum = b[i]-'0' + carry;
49            helper(carry, sum);
50            i++;
51            ans += sum + '0';
52        }
53        if(carry &1)ans += carry+'0'; 
54        reverse(ans.begin(), ans.end());
55        return ans;
56    }
57};