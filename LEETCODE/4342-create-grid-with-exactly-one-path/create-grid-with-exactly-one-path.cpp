class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string temp = "";
        for(int i =0;i<n;i++){
            temp += '#';
        }
        vector<string>ans(m, temp);
        for(int i =0;i<m;i++){
            ans[i][0] = '.';
        }
        for(int j =0;j<n;j++){
            ans[m-1][j] = '.';
        }
        return ans;
    }
};