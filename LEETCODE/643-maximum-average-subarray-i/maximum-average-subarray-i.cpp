class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        
        for(int i =0;i<k;i++){
            sum += nums[i];
            
        }
        int ans = sum;
        for(int i =k; i<n ;i++){
            sum += nums[i]; 
            sum -= nums[i-k];
            ans = max(ans, sum);
        }

        return (double)ans/(double)k;
    }
};