class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {

            vector<int> arr;

            int top = l;
            int left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            // top row
            for (int j = left; j <= right; j++)
                arr.push_back(grid[top][j]);

            // right col
            for (int i = top + 1; i <= bottom - 1; i++)
                arr.push_back(grid[i][right]);

            // bottom row
            for (int j = right; j >= left; j--)
                arr.push_back(grid[bottom][j]);

            // left col
            for (int i = bottom - 1; i >= top + 1; i--)
                arr.push_back(grid[i][left]);

            int sz = arr.size();
            int rot = k % sz;

            vector<int> rotated(sz);

            for (int i = 0; i < sz; i++) {
                rotated[i] = arr[(i + rot) % sz];
            }

            int idx = 0;

            // top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // right col
            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = rotated[idx++];

            // bottom row
            for (int j = right; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // left col
            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};