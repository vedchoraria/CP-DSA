1class Solution {
2public:
3    int minimumEffortPath(vector<vector<int>>& heights) {
4        int rows = heights.size(), cols = heights[0].size();
5        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
6        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
7        minHeap.emplace(0, 0, 0);
8        dist[0][0] = 0;
9        
10        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
11        
12        while (!minHeap.empty()) {
13            auto [effort, x, y] = minHeap.top();
14            minHeap.pop();
15            
16            if (effort > dist[x][y]) continue;
17            
18            if (x == rows - 1 && y == cols - 1) return effort;
19            
20            for (auto& dir : directions) {
21                int nx = x + dir[0], ny = y + dir[1];
22                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
23                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
24                    if (new_effort < dist[nx][ny]) {
25                        dist[nx][ny] = new_effort;
26                        minHeap.emplace(new_effort, nx, ny);
27                    }
28                }
29            }
30        }
31        return -1;
32    }
33};