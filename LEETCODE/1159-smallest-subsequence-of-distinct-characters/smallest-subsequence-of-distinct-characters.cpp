class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>f(26, 0), pres(26, 0);
        for(auto &i: s) f[i-'a']++;
        stack<char>st;
        int n = s.size();
        for(auto &c: s){
            if(pres[c-'a']){
                f[c-'a']--; continue;
            }
            while(!st.empty() && st.top() >= c && f[st.top()-'a']){
                pres[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(c);
            pres[c-'a'] = 1;
            f[c-'a']--;
        }
        string ans = "";
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};