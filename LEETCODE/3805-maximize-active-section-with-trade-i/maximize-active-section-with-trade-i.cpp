class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev = -1 , curr = -1;
        int ans = 0; int sum = 0;
        for(char c : s) if(c == '1') sum ++;
        int cnt = 0;
        ans = sum;
        if(ans == 0) return ans;
        for(int i =0;i<s.length();i++){
            if(s[i] == '0') cnt++;
            else{
                if(cnt == 0) continue;
                if(curr == -1){
                    curr = cnt; cnt = 0;
                }
                else{
                    prev = curr;
                    curr = cnt; cnt =0;
                    ans = max(ans, sum + prev+curr);
                }
            }
        }
        if(cnt>0){
            if(curr == -1){
                curr = cnt; cnt = 0;
            }
            else{
                prev = curr;
                curr = cnt; cnt =0;
                ans = max(ans, sum + prev+curr);
            }
        }

        // if(prev != -1){
        //     ans = max(ans, sum + prev+curr);
        // }
        // else if(curr != -1){ans = max(ans, sum + curr);}
        cout<<sum<<prev<<curr<<cnt<<endl;
        return ans;
    }
};