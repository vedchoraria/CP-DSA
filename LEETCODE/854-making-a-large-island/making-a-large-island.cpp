class Solution {
public:
int n,m, index=2;
vector<vector<int>>mat, vis;

int dr[4] = {-1,0,1, 0};
int dc[4] = {0,1,0,-1};

int dfs(int i , int j ){
    mat[i][j] = index;
    int sz = 1;
    for(int k = 0; k< 4;k ++){
        int nr = i + dr[k];
        int nc = j + dc[k];

        if(nr<0 ||nr>=n || nc < 0 || nc >= m) continue;
        if(mat[nr][nc] == 1){
            sz += dfs(nr, nc);
        }
    }
    return sz;
}
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> islandSizes;
        //  index = 2; // starting from 2 , because the grid has 1 or 0 
        n = grid.size(); m = grid[0].size();
        mat = grid; 
        // vis.assign(n,vector<int>(m,0));
        
        int ans = 0;
        for(int i =0; i< n; i++){
            for(int j =0 ; j < m; j ++){
                if(mat[i][j] == 1){
                    
                    islandSizes[index] = dfs(i,j);
                    ans = max(ans,islandSizes[index] );
                    index++;
                }
            }
        }  

        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    set<int>st;
                    
                    for(int k = 0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr<0 ||nr>=n || nc < 0 || nc >= m) continue;
                        if(mat[nr][nc] > 0)st.insert(mat[nr][nc]);
                    }

                    int sum = 1;
                    for(int i : st){
                        sum += islandSizes[i];
                    }

                    ans = max(ans, sum);
                }
            }
        }
        return ans;     
    }
};