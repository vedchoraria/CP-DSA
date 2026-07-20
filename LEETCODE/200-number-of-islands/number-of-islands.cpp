class Solution {
public:
vector<vector<char>> mat;
vector<vector<int>>vis;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int n ,m;
void dfs(int i , int j){
    if(vis[i][j] == 1) return;
    vis[i][j] = 1;
    for(int k = 0; k < 4 ; k++){
        int nr = i + dr[k];
        int nc = j + dc[k];
        if(nr <0 || nr >= n || nc < 0 || nc >= m) continue;
        if(vis[nr][nc] == 1) continue;
        if(mat[nr][nc] == '1') dfs(nr, nc);
    }
}

    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
        mat = grid;
        vis.assign(n, vector<int>(m,0));
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == '1'){
                    ans ++;
                    dfs(i,j);
                }
            }
        } 
        return ans;
    }
};