//Time complexity: O(n),  Space complexity: O(1)
class Solution {

    const int all_set = (1 << 5) - 1;
    
public:
    int countVowelSubstrings(string word) {

        vector<int> mask_pos(125, -1);
        int pos = 0;
        for(char ch : "aeiou") {
            mask_pos[ch] = pos++;
        }

        int ans = 0;
        vector<int> dp(1 << 5);
        vector<int> prev_dp(1 << 5);
        dp[0] = 1;
        for(auto ch : word) {
            
            pos = mask_pos[ch];

            if(pos < 0) {
                fill(dp.begin(), dp.end(), 0);
                dp[0] = 1; //#empty strings ending at position i
            } else {
                prev_dp = dp;
                dp[0] = 1;  //#empty strings ending at position i
                for(int mask = 1; mask <= all_set; mask++) {
                    if(mask & (1 << pos)) {
                        dp[mask] = prev_dp[mask] + prev_dp[mask ^ (1 << pos)];
                    } else {
                        dp[mask] = 0;
                    }
                }
                ans += dp[all_set];
            }
        }

        return ans;
    }
};