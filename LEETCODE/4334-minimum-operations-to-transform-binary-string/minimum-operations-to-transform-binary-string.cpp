class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.length();
        if(n == 1) {
            if(s1 == s2) return 0;
            else if(s1[0] == '1') return -1;
            else return 1;
        }
        int ans = -1;
        for(int i =0 ;i < n; i++){
            if(s1[i] == s2[i]) continue;
            // 0 -->  1
            if(s1[i] == '0'){
                ans ++; s1[i] = '1';
            }
            // 1 0 --> 0 0 cost = 2;
            // 1 1 --> 0 1 cost = 2;
            // 1 0 --> 0 1 cost = 3;
            // 1 1 --> 0 0 cost = 1;
            else if(i<n-1){
                // s1[i] = '0';
                if(s1[i+1] == '0' and s2[i+1] == '0') {ans += 2; }
                if(s1[i+1] == '1' and s2[i+1] == '1') {ans += 2;}
                if(s1[i+1] == '0' and s2[i+1] == '1') {ans += 3;}
                if(s1[i+1] == '1' and s2[i+1] == '0') {ans ++;}
                
                s1[i] = '0'; s1[i+1] = s2[i+1];
                
                cout<<"A"<<endl;
            }
            
            else if(i > 0){
                
                if(s1[i-1] == '0' and s2[i-1] == '0') ans += 2;
                if(s1[i-1] == '1' and s2[i-1] == '1') ans += 2;
                if(s1[i-1] == '0' and s2[i-1] == '1') ans += 3;
                if(s1[i-1] == '1' and s2[i-1] == '0') ans ++;
                s1[i] = '0'; 
                s1[i-1] = s2[i-1];
                cout<<"B"<<endl;
            }
        }
        return ((ans == -1) ? 0 : ans +1);
    }
};