class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        // transpose
        for(int i = 1; i<n; i++){
            for(int j=0; j<i; j++ ){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    for(auto it : matrix){ for(int i : it) {cout<<i<<" ";} cout<<endl;}
        //row wise reversing
        for(int i=0; i<n; i++){
            int s = 0, e = n-1;
            while(s<e){
                swap(matrix[i][s++], matrix[i][e--]);
            }
        } 
    }
};