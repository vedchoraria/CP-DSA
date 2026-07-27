const int mx = 1000;
class Solution {
    int cnt[mx][26];
public:
    int countVowelSubstrings(string s) {
        int n = s.size();
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++){
            int ch = s[i]-'a';
            if(i>0){
                for(int j=0; j<26; j++){
                    cnt[i][j] += cnt[i-1][j];
                }
            }
            cnt[i][ch] += 1;
        }
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        auto poss = [&](int l, int r){
            for(int j=0; j<26; j++){
                char ch = 'a'+j;
                if(st.find(ch) == st.end()){
                    if((cnt[r][j]-((l>0) ? cnt[l-1][j] : 0)) != 0){
                        if(r == 4) cout<<(cnt[r][j]-((l>0) ? cnt[l-1][j] : 0))<<endl;
                        return 0;
                    }
                }else{
                    if((cnt[r][j]-((l>0) ? cnt[l-1][j] : 0)) == 0){
                        return 2;
                    } 
                }
            }
            return 1;
        };
        int ans = 0;
        map<char, int>mp;
        for(int i=0; i<n; i++){
            if(st.find(s[i]) == st.end()){
                mp.clear(); continue;
            }else{
                mp[s[i]]++;
            }
            if(mp.size() != 5) continue;
            int l = -1, r = i+1, mid;
            while(r-l>1){
                mid = (l+r)/2;
                int val = poss(mid, i);
                if(val == 1) r = mid;
                else if(val == 2) r = mid;
                else l = mid;
            }
            
            if(r<i){
                int left = r;
                l = r, r = i+1;
                while(r-l>1){
                    mid = (l+r)/2;
                    if(poss(mid, i) == 1) l = mid;
                    else r = mid; 
                }
                ans += l-left+1;
            }
        }
        return ans;
    }   
};