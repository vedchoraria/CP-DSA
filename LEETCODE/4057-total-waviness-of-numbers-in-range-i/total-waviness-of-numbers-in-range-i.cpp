class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int x=num1;x<=num2;x++){
            string s=to_string(x);
            for(int i=1;i<s.size()-1;i++){
                bool isPeak = s[i]>s[i-1] && s[i]>s[i+1];
                bool isValley = s[i]<s[i-1] && s[i]<s[i+1];
                if(isPeak || isValley){
                    ans++;;
                }
            }
        }
        return ans;
    }
};