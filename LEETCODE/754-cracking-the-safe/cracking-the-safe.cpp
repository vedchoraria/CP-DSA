class Solution {
public:
unordered_set<string >st;
        string ans;
        
        void backtrack(string t, int k){
            for(int i =0;i < k; i++){
                char ch = '0' + i;
                string f = t + ch;
                if(st.find(f) == st.end()){
                    st.insert(f);
                    backtrack(f.substr(1) , k);
                    ans += ch;
                }
            }
        }

    string crackSafe(int n, int k) {
        
        string start = "";
        for(int i  =1;i<=n-1;i++) start += '0';
        backtrack(start,k);
        return ans + start;
    }
};