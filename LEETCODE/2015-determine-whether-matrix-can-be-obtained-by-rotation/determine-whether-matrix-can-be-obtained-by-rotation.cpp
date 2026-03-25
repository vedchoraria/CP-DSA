class Solution {
    void ratate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1-i; j++){
                swap(mat[i][j], mat[n-1-j][n-1-i]);
            }
        }
        for(int i=0; i<n/2; i++){
            for(int j = 0; j<n; j++){
                swap(mat[i][j], mat[n-1-i][j]);
            }
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        ratate(mat);
        if(mat == target) return true;
        ratate(mat);
        if(mat == target) return true;
        ratate(mat);
        if(mat == target) return true;
        return false;
    }
};