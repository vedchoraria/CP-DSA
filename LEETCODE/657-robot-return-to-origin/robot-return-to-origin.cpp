class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0 , right = 0 , up = 0 , down = 0;
        for(auto it : moves){
            if(it == 'U') up++;
            if(it == 'D') down++;
            if(it == 'L') left++;
            if(it == 'R') right++;
        }

        return (up == down && left == right);
    }
};