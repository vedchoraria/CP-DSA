class Solution {
    string ans;
    void find(int i, string str, string &tar, vector<int>&f){
        int n = tar.size();
        if(n&1){
            if(i == n/2){
                for(int j=0; j<26; j++){
                    if(f[j]){
                        string temp = str;
                        str += 'a'+j;
                        reverse(temp.begin(), temp.end());
                        str += temp;
                        if(str > tar){
                            if(ans == "") ans = str;
                            else ans = min(ans, str);
                        }
                        return;
                    }
                }
            }
            int ch = (tar[i]-'a');
            if(f[ch]>1){
                str += tar[i];
                f[ch] -= 2;
                find(i+1, str, tar, f);
                str.pop_back();
                f[ch] += 2;
            }
            for(int j=ch+1; j<26; j++){
                if(f[j]>1){
                    str += 'a'+j;
                    f[j] -= 2;
                    string temp = "";
                    char od = 'a';
                    for(int k=0; k<26; k++){
                        char ch2 = 'a'+k;
                        if(f[k]&1) od = ch2;
                        for(int l=0; l<f[k]/2; l++) temp += ch2;
                    }
                    sort(temp.begin(), temp.end());
                    str += temp;
                    string temp2 = str;
                    // cout<<str<<" "<<od<<" "<<temp2<<endl;
                    reverse(temp2.begin(), temp2.end());
                    str += od;
                    str += temp2;
                    if(ans == "") ans = str;
                    else ans = min(ans, str);
                    return;
                }
            }
        }else{
            if(i == n/2){
                string temp = str;
                reverse(temp.begin(), temp.end());
                str += temp;
                if(str > tar){
                    if(ans == "") ans = str;
                    else ans = min(ans, str);
                }
                return;
            }
            int ch = (tar[i]-'a');
            if(f[ch]){
                str += tar[i];
                f[ch] -= 2;
                find(i+1, str, tar, f);
                f[ch] += 2;
                str.pop_back();
            }
            for(int j=ch+1; j<26; j++){
                if(f[j]){
                    str += 'a'+j;
                    f[j] -= 2;
                    string temp = "";
                    for(int k=0; k<26; k++){
                        char ch2 = 'a'+k;
                        for(int l=0; l<f[k]/2; l++) temp += ch2;
                    }
                    sort(temp.begin(), temp.end());
                    str += temp;
                    string temp2 = str;
                    reverse(temp2.begin(), temp2.end());
                    str += temp2;
                    if(ans == "") ans = str;
                    else ans = min(ans, str);
                    return;
                }
            }
        }
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int>f(26, 0);
        for(auto &i: s){
            f[i-'a']++;
        }
        int oc = 0, n = s.size();
        for(int i=0; i<26; i++) oc += (f[i]&1);
        if(n%2 == 0){
            if(oc) return "";
        }else{
            if(oc > 1) return "";
        }
        string temp = "";
        char od = 'a';
        for(int i=25; i>=0; i--){
            char ch = 'a'+i;
            for(int j=0; j<f[i]/2; j++) temp += ch;
            if(f[i]&1) od = ch;
        }
        string str2 = temp;
        if(n&1) str2 += od;
        reverse(temp.begin(), temp.end());
        str2 += temp;
        if(str2 <= target) return "";
        ans = "";
        string str = "";
        find(0, str, target, f);
        return ans;
    }
};