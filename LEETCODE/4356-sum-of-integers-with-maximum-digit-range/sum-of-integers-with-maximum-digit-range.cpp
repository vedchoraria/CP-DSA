class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int>vec(10,0);
        for(int i : nums){
            string a = to_string(i);
            sort(a.begin(), a.end());
            int t = abs(a[0] - a[a.size() - 1]);
            vec[t] += i;
        }
        for(int i =9;i>=0;i--){
            if(vec[i]  != 0) return vec[i];
        }
        return 0;
    }
};