1class Solution {
2public:
3    int minRemovals(vector<int>& nums, int target) {
4
5        int n = nums.size();
6
7        // Maximum possible XOR value constraint
8        int MAXX = 1e5;
9
10        // dp[i] = maximum number of elements we can pick such that XOR = i
11        // initialize with -1 (means not possible)
12        vector<int> dp(MAXX + 1, -1);
13
14        // Base case: XOR = 0 is possible with 0 elements
15        dp[0] = 0;
16
17        // Iterate through each number in the array
18        for (int x : nums) {
19
20            // Create a copy of dp to update safely
21            vector<int> ndp = dp;
22
23            // Try including current element x
24            for (int i = 0; i <= MAXX; i++) {
25
26                // If XOR = i is achievable
27                if (dp[i] != -1) {
28
29                    // New XOR after including x = i ^ x
30                    // Update maximum elements used
31                    ndp[i ^ x] = max(ndp[i ^ x], dp[i] + 1);
32                }
33            }
34
35            // Move updated values back to dp
36            dp = ndp;
37        }
38
39        // If target XOR is not achievable
40        if (dp[target] == -1)
41            return -1;
42
43        // We want minimum removals
44        // = total elements - maximum elements we can keep
45        return n - dp[target];
46    }
47};