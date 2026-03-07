1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int maxProd = nums[0];
5        int minProd = nums[0];
6        int ans = nums[0];
7
8        for(int i = 1; i < nums.size(); i++){
9            
10            if(nums[i] < 0)
11                swap(maxProd, minProd);
12
13            maxProd = max(nums[i], nums[i] * maxProd);
14            minProd = min(nums[i], nums[i] * minProd);
15
16            ans = max(ans, maxProd);
17        }
18
19        return ans;
20    }
21};