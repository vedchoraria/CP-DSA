class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>mpp;
        for(string p : patterns)
        mpp[p]++;

        int ans = 0, n = word.length();
        for(int i =0;i<n;i++){
            string temp = "";
            for(int j = i; j<n;j++){
                temp += word[j];
                if(mpp[temp]) {
                    ans+=mpp[temp];
                    mpp[temp] = 0;
                }
            }
        }

        return ans;
    }
};