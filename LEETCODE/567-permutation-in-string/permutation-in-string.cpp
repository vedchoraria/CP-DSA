class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Step 1: fill freq1
        for(char c : s1) {
            freq1[c - 'a']++;
        }

        // Step 2: first window
        for(int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Step 3: check first window
        if(freq1 == freq2) return true;

        // Step 4: slide window
        for(int i = n; i < m; i++) {
            // add new character
            freq2[s2[i] - 'a']++;

            // remove old character
            freq2[s2[i - n] - 'a']--;

            // compare
            if(freq1 == freq2) return true;
        }

        return false;
    }
};