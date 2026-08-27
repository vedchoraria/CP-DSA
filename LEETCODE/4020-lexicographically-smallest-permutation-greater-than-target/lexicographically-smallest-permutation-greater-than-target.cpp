class Solution {
    string ans;
    void find(int i, string &str, string &t, vector<int>&f){
        int n = t.size();
        if(i == n){
            return;
        }
        if(f[t[i]-'a']){
            str += t[i];
            f[t[i]-'a']--;
            find(i+1, str, t, f);
            str.pop_back();
            f[t[i]-'a']++;
        }
        for(int j=t[i]-'a'+1; j<26; j++){
            if(f[j]){
                string temp = str;
                temp += ('a'+j);
                f[j]--;
                for(int k=0; k<26; k++){
                    char ch = 'a'+k;
                    for(int l=0; l<f[k]; l++){
                        temp += ch;
                    }
                }
                if(ans == "") ans = temp;
                else ans = min(ans, temp);
                
            }
        }
        return;
    }
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int>f(26, 0);
        for(auto &i: s) f[i-'a']++;
        string str = "";
        ans = "";
        find(0, str, t, f);
        return ans;
    }
};