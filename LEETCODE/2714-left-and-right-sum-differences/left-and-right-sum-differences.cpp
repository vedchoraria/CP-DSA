class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        vector<int>ans;
        for(auto i:nums){
            curr += i;
            ans.push_back(abs(sum -2*curr+i));
            
        }
        return ans;
    }
};