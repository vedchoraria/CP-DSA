class Solution {
public:
    
      
    string decodeCiphertext(string et, int rows) {
        int n = et.length();
        //BASE CASE : 
        if(n<1 || rows < 2) return et;
        int i =0 , temp = 0 , col = n/rows;
        vector<string>words;
        for(i;i<n;i= i+col){
            words.push_back(et.substr(i+temp,col));
            temp++;
        }
        string ans = "";
        for(int j = 0;j<words[0].size();j++){
            for(int i =0;i<rows;i++)
            if(j<words[i].size())
            ans += words[i][j];
        }
        while(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};