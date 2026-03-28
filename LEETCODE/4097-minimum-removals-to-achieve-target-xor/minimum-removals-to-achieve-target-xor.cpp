class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {

        int n = nums.size();

        // Maximum possible XOR value constraint
        int MAXX = 1e5;

        // dp[i] = maximum number of elements we can pick such that XOR = i
        // initialize with -1 (means not possible)
        vector<int> dp(MAXX + 1, -1);

        // Base case: XOR = 0 is possible with 0 elements
        dp[0] = 0;

        // Iterate through each number in the array
        for (int x : nums) {

            // Create a copy of dp to update safely
            vector<int> ndp = dp;

            // Try including current element x
            for (int i = 0; i <= MAXX; i++) {

                // If XOR = i is achievable
                if (dp[i] != -1) {

                    // New XOR after including x = i ^ x
                    // Update maximum elements used
                    ndp[i ^ x] = max(ndp[i ^ x], dp[i] + 1);
                }
            }

            // Move updated values back to dp
            dp = ndp;
        }

        // If target XOR is not achievable
        if (dp[target] == -1)
            return -1;

        // We want minimum removals
        // = total elements - maximum elements we can keep
        return n - dp[target];
    }
};