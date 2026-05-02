class Solution {
public:
// 3 4 7
//0 1 8 alone not valid
// 2 5 6 9
bool check(int ch){
    bool an = false;
    while(ch!=0){
        int digit = ch%10;
        if(digit == 3 || digit == 4 || digit == 7) return false;
        if(digit == 2 || digit == 5 || digit == 6 || digit == 9) an = true;
        ch /= 10;
    }
    return an;
}
    int rotatedDigits(int n) { int cnt =0;
        for(int i =2;i<=n;i++){
            cnt += check(i);

        }
        return cnt;
    }
};