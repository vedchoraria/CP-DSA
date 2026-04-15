1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int limit) {
4        multiset<int>st;
5        int ans =0; int left =0; int n = nums.size();
6        for(int right = 0 ; right < n; right++){
7            st.insert(nums[right]);
8
9            
10            while((*st.rbegin() - *st.begin()) > limit) {
11                st.erase(st.find(nums[left])); left++;
12            }
13            
14            ans = max(ans, right- left+1);
15            
16        }
17        return ans;
18    }
19};