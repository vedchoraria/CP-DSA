1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int startIndex) {
4        int n=words.size(),ans=INT_MAX;
5        for(int i=0;i<n;i++){
6            if(words[i]==target){
7                int dif=abs(i-startIndex);
8                ans=min(ans,min(dif,n-dif));
9            }
10        }
11        return ans==INT_MAX?-1:ans;
12    }
13};