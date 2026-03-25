typedef pair<int, pair<int, int>> node;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<node, std::vector<node>, std::greater<node>> pq;
        int rows = heights.size() , cols = heights[0].size();
        vector<vector<int>>dist(rows, vector<int> (cols, INT_MAX));
        vector<pair<int,int>>dir = {
            {1,0} , {-1,0} , {0 , 1}, {0,-1}
        };

        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto[effort , pos] = pq.top();
            int r = pos.first , c= pos.second;
            pq.pop();
            if( r == rows -1 && c == cols-1)return effort;

            for(auto[dr , dc] : dir){
                int nr = r+dr , nc = c+dc;
                if(nr>=0 && nr<rows && nc >=0 && nc < cols){
                    int newEffort = max(effort , abs(heights[r][c] - heights[nr][nc]));
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort , {nr , nc}});
                    }
                    
                }
            }
        }
        return 0;
    }
};