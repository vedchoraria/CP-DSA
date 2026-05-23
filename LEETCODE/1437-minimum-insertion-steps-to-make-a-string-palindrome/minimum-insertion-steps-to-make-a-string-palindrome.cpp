class Solution {
public:

    int lcs(string &s1, string &s2){

        int n=s1.size();

        vector<int>curr(n+1, 0);
        vector<int>prev(n+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j], curr[j-1]);
                }
            }
            prev=curr;
        }

        return prev[n];

    }

    int minInsertions(string s) {

        int n =s.size();
        string t=s;
        reverse(t.begin(), t.end());

        return n-lcs(s, t);
    }
};