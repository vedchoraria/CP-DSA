class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        vector<int> before(n), after(n);
        // before | char | after


        // Match before from left
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;

            if (j == m)
                before[i] = m;
            else
                before[i] = j++;
        }

        // Already a subseq
        if (before[n - 1] != m)
            return true;

        // Match after from right
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;

            if (j < 0)
                after[i] = -1;
            else
                after[i] = j--;
        }

        // char check
        for (int i = 0; i < n; i++) {

            // before ( i-1) | char ( i) | after ( i+1)

            int left = (i == 0) ? -1 : before[i - 1];
            int right = (i == n - 1) ? m : after[i + 1];
      // like spose 0 1 2 3 4 5 6 7
             //       ^     ^
             //     left  right
            // left = m then its out of bound same for right = -1 
            // there must be a gap
            if (left != m && right != -1 && right - left > 1)
                return true;
        }

        return false;
    } };