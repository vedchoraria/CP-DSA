1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4        int n = height.size();
5        int i=0, j = n-1; int area = INT_MIN;
6        while(i<j){
7            int h = min(height[i],height[j]);
8            int b = j-i;
9            area = max(h*b, area);
10            if(height[i] > height[j]){
11                j--;
12            }
13            else i++;
14        }
15        // for(i,j ; i<j ;){
16        //     area = max(area, min(height[i],height[j])* (j-i));
17        //     height[i] > height[j] ? j-- : i++;
18        // }
19        return area;
20    }
21};