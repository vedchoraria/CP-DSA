class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<string>temp;
        for(string c : words) temp.push_back(c);
        for(string c : words) temp.push_back(c);
        int n = temp.size();
        int ans = INT_MAX;
        int t = startIndex;
        startIndex += n/2;
        
        for(int i =0;i<n;i++){
            if(temp[i] == target){
                ans = min(ans , abs(i-t));
                ans = min(ans , abs(i-startIndex));
            }
        }

        return (ans == INT_MAX)?-1 : ans;
    }
};