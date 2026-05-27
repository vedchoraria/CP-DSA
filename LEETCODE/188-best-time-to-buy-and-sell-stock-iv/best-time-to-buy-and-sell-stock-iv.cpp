
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // index, buy, cap

int n = prices.size();
        vector<vector<int>> prev (2, vector<int>(k+1, 0));
        vector<vector<int>> curr (2, vector<int>(k+1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = k; cap > 0; cap--) {
                    int profit = 0;
                    if (buy) {
                        int buyKaro = -prices[index] + prev[0][cap];
                                      
                        int skipKaro = 0 + prev[1][cap]; 
                        profit = max(buyKaro, skipKaro);
                    } else {
                        int sellKaro = prices[index] + prev[1][cap-1];
                        int skipKaro = 0 + prev[0][cap]; 
                        profit = max(sellKaro, skipKaro);
                    }
                    curr[buy][cap] = profit;
                }
            }

            prev = curr;
        }

        return curr[1][k];
    }
};