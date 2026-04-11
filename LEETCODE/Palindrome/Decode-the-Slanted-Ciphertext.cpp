1class Solution {
2public:
3    
4      
5    string decodeCiphertext(string et, int rows) {
6        int n = et.length();
7        //BASE CASE : 
8        if(n<1 || rows < 2) return et;
9        int i =0 , temp = 0 , col = n/rows;
10        vector<string>words;
11        for(i;i<n;i= i+col){
12            words.push_back(et.substr(i+temp,col));
13            temp++;
14        }
15        string ans = "";
16        for(int j = 0;j<words[0].size();j++){
17            for(int i =0;i<rows;i++)
18            if(j<words[i].size())
19            ans += words[i][j];
20        }
21        while(ans.back() == ' ') ans.pop_back();
22        return ans;
23    }
24};