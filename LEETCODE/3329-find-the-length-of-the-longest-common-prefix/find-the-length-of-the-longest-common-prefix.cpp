class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        unordered_set<int>prefix;
        for(int i : a){
            while(i!=0 && !prefix.count(i)){
                prefix.insert(i);
                i/=10;
            }
        }
        int len =0;
        for(int i : b){
            while(!prefix.count(i) && i>0){
                i=i/10;
            }

            if(i!=0) len = max(len, (int)(to_string(i).length()));
        }
        return len;
    }
};