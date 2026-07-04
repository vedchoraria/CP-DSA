class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        // cnt denotes x-y , x is the majourity element and y is the minimum element 
        int ans =0;
        for(int i : nums){
            if(cnt == 0){
                ans = i; cnt++;
            }
            else if(ans == i) cnt++;
            else cnt--;
        }
        return ans;
    }
};