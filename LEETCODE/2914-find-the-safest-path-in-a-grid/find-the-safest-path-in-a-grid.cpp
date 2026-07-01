class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue< pair<int,int> >q;
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,1e8));

        for(int i= 0 ;i <n ;i ++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        int dx[4] = {-1 , 0, 1 , 0};
        int dy[4] = { 0 , 1 ,0 ,-1};

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k =0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x>=0 and x<n and y>=0 and y<n and dis[x][y] > dis[i][j]+1){
                    dis[x][y] = dis[i][j] +1;
                    q.push({x,y});
                }
            }

        }

        // [0,0] --> [n-1,n-1]
        // x,y,safety factor
        vector<vector< bool>>vis(n,vector<bool>(n,false));
        priority_queue< pair< int ,pair<int,int> > > pq;
        pq.push({dis[0][0] , {0,0} });

        while(!pq.empty()){
            auto [d, it] = pq.top();
            auto [i,j] = it;
            pq.pop();
            if(i == n-1 and j == n-1) return d;

            for(int k = 0; k<4; k++){
                int x = i+dx[k], y = j + dy[k];
                if(x>=0 and x<n and 
                   y>=0 and y<n and 
                   vis[x][y] == false ){

                    vis[x][y] = true;
                    int mi = min(dis[x][y], d);
                    pq.push({mi , {x,y}});
                }
            }
        }
        return -1;
    }
};