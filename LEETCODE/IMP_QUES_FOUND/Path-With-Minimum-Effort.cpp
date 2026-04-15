1typedef pair<int, pair<int, int>> node;
2class Solution {
3public:
4    int minimumEffortPath(vector<vector<int>>& heights) {
5        priority_queue<node, std::vector<node>, std::greater<node>> pq;
6        int rows = heights.size() , cols = heights[0].size();
7        vector<vector<int>>dist(rows, vector<int> (cols, INT_MAX));
8        vector<pair<int,int>>dir = {
9            {1,0} , {-1,0} , {0 , 1}, {0,-1}
10        };
11
12        pq.push({0,{0,0}});
13        dist[0][0] = 0;
14        while(!pq.empty()){
15            auto[effort , pos] = pq.top();
16            int r = pos.first , c= pos.second;
17            pq.pop();
18            if( r == rows -1 && c == cols-1)return effort;
19
20            for(auto[dr , dc] : dir){
21                int nr = r+dr , nc = c+dc;
22                if(nr>=0 && nr<rows && nc >=0 && nc < cols){
23                    int newEffort = max(effort , abs(heights[r][c] - heights[nr][nc]));
24                    if(newEffort < dist[nr][nc]){
25                        dist[nr][nc] = newEffort;
26                        pq.push({newEffort , {nr , nc}});
27                    }
28                    
29                }
30            }
31        }
32        return 0;
33    }
34};