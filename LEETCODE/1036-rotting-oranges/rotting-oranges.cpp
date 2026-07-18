class Solution {
public:
int dr[4] = {-1,0,1,0};
int dc[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue< pair<int,int> >q;
        

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }



        int t = -1;
        while(!q.empty()){
            int z = q.size();

            t++;

            for(int i =0;i<z;i++){
                auto rotten = q.front();
                q.pop();
                int r = rotten.first;
                int c = rotten.second;
                
                for(int k =0; k<4 ;k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr>=0 && nc>=0 and nc<m and nr < n and grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                    }
                }
            }
        }

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return (t == -1) ? 0 : t;
        
    }
};