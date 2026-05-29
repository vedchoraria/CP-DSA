class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        vector<int> prev(n, 0);
        int len = 1;
        int len_id = 0;

        for (int i = 1; i < n; i++) {
            prev[i] = i;
            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                    prev[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }

            if (dp[i] > len) {
                len = dp[i];
                len_id = i;
            }
        }
        for (int i : dp)
            cout << i << " ";
        cout << endl;
        for (int i : prev)
            cout << i << " ";
        cout << endl;
        vector<int> res;
        while (prev[len_id] != len_id) {
            res.push_back(nums[len_id]);
            len_id = prev[len_id];
        }
        res.push_back(nums[len_id]);
        reverse(res.begin(), res.end());
        return res;
    }
};
