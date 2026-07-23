class Solution {
public:
// 3 = 11
// 2 = 10
// 1 = 01
// last digit : 1 , 0 
// second last mei bhi 2 
    int uniqueXorTriplets(vector<int>& nums) {

        if(nums.size() <=2) return nums.size();
        
        int ma = *max_element(nums.begin(), nums.end());
        int mi = *min_element(nums.begin(), nums.end());

        int n =0;
        while(ma != 0){
            n++;
            ma = ma>>1;
        }

        int ans = pow(2, n);
        return ans;
    }
};