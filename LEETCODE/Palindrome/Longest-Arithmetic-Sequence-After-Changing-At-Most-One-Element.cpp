1class Solution {
2public:
3    int longestArithmetic(vector<int>& nums) {
4        int n = nums.size();
5
6        // If size is <= 2, entire array is already arithmetic
7        if (n <= 2) return n;
8
9        // L[i] = length of arithmetic subarray ending at i
10        // R[i] = length of arithmetic subarray starting at i
11        vector<int> L(n, 2), R(n, 2);
12
13        // Fill L[] (left to right)
14        for (int i = 2; i < n; ++i) {
15            // Check if current difference matches previous difference
16            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
17                L[i] = L[i - 1] + 1;  // extend sequence
18            }
19        }
20
21        // Fill R[] (right to left)
22        for (int i = n - 3; i >= 0; --i) {
23            // Check if forward difference matches
24            if (nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) {
25                R[i] = R[i + 1] + 1;  // extend sequence
26            }
27        }
28
29        int ans = 2;  // minimum arithmetic length
30
31        for (int i = 0; i < n; ++i) {
32
33            // Case 1: Extend from left side
34            if (i > 0)
35                ans = max(ans, L[i - 1] + 1);
36
37            // Case 2: Extend from right side
38            if (i < n - 1)
39                ans = max(ans, R[i + 1] + 1);
40
41            // Case 3: Modify nums[i] to connect both sides
42            if (i > 0 && i < n - 1) {
43
44                // Check if middle can be adjusted to form arithmetic sequence
45                if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
46
47                    int d = (nums[i + 1] - nums[i - 1]) / 2;
48
49                    int l_len = 1, r_len = 1;
50
51                    // Check left extension
52                    if (i >= 2 && nums[i - 1] - nums[i - 2] == d)
53                        l_len = L[i - 1];
54
55                    // Check right extension
56                    if (i <= n - 3 && nums[i + 2] - nums[i + 1] == d)
57                        r_len = R[i + 1];
58
59                    // Combine both sides + modified element
60                    ans = max(ans, l_len + r_len + 1);
61                }
62            }
63        }
64
65        return ans;
66    }
67};