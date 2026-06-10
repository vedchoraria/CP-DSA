class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp1, mpp2;
        int n = s.length();
        
        for(int i =0;i<n;i++){
            if(mpp1.find(s[i]) == mpp1.end() && mpp2.find(t[i]) == mpp2.end()){
                mpp1[s[i]] = t[i];
                mpp2[t[i]] = s[i];
                continue;
            } 
            else if(mpp1.find(s[i]) == mpp1.end()) return false;
            else if(mpp2.find(t[i]) == mpp2.end()) return false;

            if(mpp1[s[i]] != t[i] || mpp2[t[i]] != s[i]) return false;
        }
        return true;
    }
};