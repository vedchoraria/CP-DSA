class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>lower(26,-1) , upper(26,-1);
        int n = s.length();
        for(int i =0;i<n;i++){
            if('a' <= s[i] && s[i] <= 'z') lower[s[i]-'a'] = i;
            if('A' <= s[i] && s[i] <= 'Z' && upper[s[i]-'A'] == -1) upper[s[i]-'A'] = i;
        }

        int ans =0;
        for(int i =0;i<26;i++){
            if(lower[i] != -1 && upper[i] != -1){
                if(lower[i] < upper[i]) ans++;
            }
        }
        return ans;
    }
};