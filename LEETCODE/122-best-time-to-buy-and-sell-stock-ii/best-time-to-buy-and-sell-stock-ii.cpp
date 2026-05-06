class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , 
        buy = prices[0] , 
        ans =0;
        for(int i =1;i<n;i++){
            if(prices[i] >= buy){
                ans += prices[i]-buy;
                buy = prices[i];
            }
            else buy = prices[i];
        }
        return ans;
        
    }
};