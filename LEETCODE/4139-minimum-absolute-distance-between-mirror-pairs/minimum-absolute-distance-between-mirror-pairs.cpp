class Solution {
public:
    int rev(int n ){
        int ans = 0;
        while(n){
            ans*= 10;
            ans+= n%10;
            n/=10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int ans = 1e7 ,n = nums.size();
        for(int i =0;i<n;i++){
            int temp = rev(nums[i]);
            if(mpp.find(nums[i]) != mpp.end()) ans = min(ans , i-mpp[nums[i]]);
            mpp[temp] = i;
        }
        return (ans==1e7)?-1:ans;

    }
};