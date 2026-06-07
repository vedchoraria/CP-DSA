class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        bool alice = true;
        int n = piles.size();
        int cnt = 0;
        int i =0 , j = n-1;
        while(i <= j){
            int temp = 0;
            if(piles[i] > piles[j]){
                temp += piles[i];
                i++;
            }
            else if(piles[i] < piles[j]){
                temp += piles[j];
                j--;
            }
            else{
                if(i < n-1 && j > 0 && piles[i+1] > piles[j-1] ){
                    temp += piles[j];
                    j--;
                }
                else {
                    temp += piles[i];
                    i++;
                }
            }

            if(alice) cnt += temp;
            else cnt -= temp;

        }

        if(cnt >= 0) return true;
        else return false;
    }
};