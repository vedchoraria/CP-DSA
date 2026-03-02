1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5        vector<int> zeros(n);
6
7        // count trailing zeros
8        for(int i = 0; i < n; i++){
9            int count = 0;
10            for(int j = n-1; j >= 0 && grid[i][j] == 0; j--)
11                count++;
12            zeros[i] = count;
13        }
14
15        int swaps = 0;
16
17        for(int i = 0; i < n; i++){
18            int needed = n - i - 1;
19            int j = i;
20
21            while(j < n && zeros[j] < needed)
22                j++;
23
24            if(j == n) return -1;
25
26            while(j > i){
27                swap(zeros[j], zeros[j-1]);
28                swaps++;
29                j--;
30            }
31        }
32
33        return swaps;
34    }
35};