class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = -1;

        // Change this line! Check only i < s.size()
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (j < p.size() && p[j] == '*') {
                match = i;
                star = j;
                j++;
            }
            else if (star != -1) {
                match++;
                i = match;
                j = star + 1;
            }
            else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*') j++;

        return i == s.size() && j == p.size();
    }
};