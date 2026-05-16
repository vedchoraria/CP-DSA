class Solution {
public:
    int solve1(int row,int col, int m , int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row == m-1 && col == n-1){
            return grid[row][col];
        }
        if(row >= m || col >= n) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int down = solve1(row+1, col , m , n, grid, dp) + grid[row][col];
        int right = solve1(row, col+1, m , n, grid , dp) + grid[row][col];
        return dp[row][col]=min(down, right);
    }
    int solve2(int row,int col, int m , int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row <0 || col <0) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int up = solve2(row-1, col , m , n, grid, dp) + grid[row][col];
        int left = solve2(row, col-1, m , n, grid , dp) + grid[row][col];
        return dp[row][col]=min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
      return solve2(m-1,n-1,m,n,grid,dp);  
    }
};