class Solution {
public:
    string convertToTitle(int i) {
        string ans;

        while (i) {
            
         
            ans = ans + (char)((i-1) % 26 + 'A');
            i = (i-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};