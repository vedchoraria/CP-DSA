class Solution {
public:
void f(int i, string &s, set<string> &dic, string &temp , vector<string> &ans){
        if(i == s.size()){ans.push_back(temp); return;}
    for(int end = i+1; end <= s.size(); end++){
        string word = s.substr(i, end -i);
        if(dic.count(word)){
            string next = temp.empty() ? word : temp + " " + word;
            f(end, s, dic, next , ans);
        }

    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dic(wordDict.begin(), wordDict.end());
        string temp = "";
        vector<string> ans;
        f(0, s, dic, temp , ans);
        return ans;
    }
};