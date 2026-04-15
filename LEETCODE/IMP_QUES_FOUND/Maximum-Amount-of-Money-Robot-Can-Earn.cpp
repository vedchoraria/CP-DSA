1class Solution {
2public:
3    int maximumAmount(vector<vector<int>>& coins) {
4        int n = coins.size();
5        int m = coins[0].size();
6        //RECURSION
7        // return helper(coins , 0 , 0 , 2);
8
9        // RECURSIon + Memoization 
10        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
11        return helper(dp , coins , 0 , 0 , 2);
12    }
13    int helper(vector<vector<vector<int>>> &dp, vector<vector<int>>& coins , int i , int j , int skips){
14
15        
16        int n = coins.size();
17        int m = coins[0].size();
18            // Base Case
19        if(i>=n || j>=m) return -1e7;
20        if(i == n-1 && j == m-1){
21            if(coins[i][j] < 0 && skips > 0) return 0;
22            return coins[i][j];
23        }
24
25
26        if(dp[i][j][skips] != -1e9) return dp[i][j][skips];
27
28
29        // right
30        int right = helper(dp , coins , i , j+1 , skips) + coins[i][j];
31        int down = helper(dp , coins , i+1 , j , skips) + coins[i][j];
32        int take = max(right , down);
33        int skip = -1e6;
34        if(coins[i][j] < 0 && skips > 0){
35            skip = max(
36                helper(dp , coins , i , j+1 , skips-1) , 
37                helper(dp , coins , i+1 , j , skips-1)
38            );
39        }
40
41        return dp[i][j][skips] = max(take , skip);
42    }
43
44    // int helper(vector<vector<int>>& coins , int i , int j , int skips){
45    //     int n = coins.size();
46    //     int m = coins[0].size();
47
48    //     // Base Case
49    //     if(i>=n || j>=m) return -1e7;
50
51    //     if(i == n-1 && j == m-1){
52    //         if(coins[i][j] < 0 && skips > 0) return 0;
53    //         return coins[i][j];
54    //     }
55
56    //     //right
57    //     int right = helper(coins , i , j+1 , skips) + coins[i][j];
58    //     int down = helper(coins , i+1 , j , skips) + coins[i][j];
59    //     int take = max(right , down);
60    //     int skip = -1e6;
61    //     if(coins[i][j] < 0 && skips > 0){
62    //         skip = max(
63    //             helper(coins , i , j+1 , skips-1) , 
64    //             helper(coins , i+1 , j , skips-1)
65    //         );
66    //     }
67
68    //     return max(take , skip);
69    // }
70
71    
72};