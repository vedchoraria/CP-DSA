class Solution {
public:
vector<vector<string>>ans; vector<string>temp;
bool check(int i , int j, string &s){
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
void solve(int i , string &s){
    int n = s.length();
    if(i >= n) {ans.push_back(temp); return;}

    for(int j = i; j < n; j++){
        if(check(i,j,s)){
            temp.push_back(s.substr(i,j-i+1));
            solve(j+1, s);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};