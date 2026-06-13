class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char, int>mpp;


        for(int i =0;i<26;i++){
            mpp[i + 'a'] = weights[i];
        }

        string ans = "";

        for(auto it : words){
            int sum =0;
            for(char c : it){
                sum += mpp[c];
            }
            ans += 'a' + 25 - (sum%26);
        }

        return ans;
    }
};