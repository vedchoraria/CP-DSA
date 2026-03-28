class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();

        // If size is <= 2, entire array is already arithmetic
        if (n <= 2) return n;

        // L[i] = length of arithmetic subarray ending at i
        // R[i] = length of arithmetic subarray starting at i
        vector<int> L(n, 2), R(n, 2);

        // Fill L[] (left to right)
        for (int i = 2; i < n; ++i) {
            // Check if current difference matches previous difference
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                L[i] = L[i - 1] + 1;  // extend sequence
            }
        }

        // Fill R[] (right to left)
        for (int i = n - 3; i >= 0; --i) {
            // Check if forward difference matches
            if (nums[i + 2] - nums[i + 1] == nums[i + 1] - nums[i]) {
                R[i] = R[i + 1] + 1;  // extend sequence
            }
        }

        int ans = 2;  // minimum arithmetic length

        for (int i = 0; i < n; ++i) {

            // Case 1: Extend from left side
            if (i > 0)
                ans = max(ans, L[i - 1] + 1);

            // Case 2: Extend from right side
            if (i < n - 1)
                ans = max(ans, R[i + 1] + 1);

            // Case 3: Modify nums[i] to connect both sides
            if (i > 0 && i < n - 1) {

                // Check if middle can be adjusted to form arithmetic sequence
                if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {

                    int d = (nums[i + 1] - nums[i - 1]) / 2;

                    int l_len = 1, r_len = 1;

                    // Check left extension
                    if (i >= 2 && nums[i - 1] - nums[i - 2] == d)
                        l_len = L[i - 1];

                    // Check right extension
                    if (i <= n - 3 && nums[i + 2] - nums[i + 1] == d)
                        r_len = R[i + 1];

                    // Combine both sides + modified element
                    ans = max(ans, l_len + r_len + 1);
                }
            }
        }

        return ans;
    }
};