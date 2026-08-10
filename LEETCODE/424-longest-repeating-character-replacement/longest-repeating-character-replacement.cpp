class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int ans = 0;
        int left = 0, maxf = 0;
        for(int right = 0; right < s.length(); right++){
            freq[s[right] - 'A']++;
            maxf = *max_element(freq.begin(), freq.end());
            while( (right - left + 1) - maxf > k){
                freq[s[left] - 'A']--;
                left++;
                maxf = *max_element(freq.begin(), freq.end());
            }
            maxf = *max_element(freq.begin(), freq.end());
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};