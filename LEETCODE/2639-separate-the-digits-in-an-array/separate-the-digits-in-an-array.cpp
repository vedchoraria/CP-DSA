class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i : nums){
            stack<int>st;
            while(i != 0){
                int dig = i%10;
                i/=10;
                st.push(dig);
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;   
    }
};