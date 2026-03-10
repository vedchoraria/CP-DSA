class Solution {
public:
    void solve(deque<int> &dq , vector<int>& nums , int &i , int &k , vector<int>& ans){
        ans.push_back(nums[dq.front()]);
        while(!dq.empty() && dq.front() <= i-k ) dq.pop_front();

        while( !dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
    }



    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size();

        //FIRST K ELEMENTS
        for(int i =0; i<k;i++){
            while( !dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

            dq.push_back(i);
        }
        vector<int>ans;
        for(int i = k; i<n;i++){
            solve(dq , nums , i , k , ans);
        }

        ans.push_back( nums[dq.front()] );
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         deque<int> dq;

//         for (int i = 0; i < n; i++) {
//             // Remove indices outside the window
//             if (!dq.empty() && dq.front() <= i - k) 
//                 dq.pop_front();

//             // Maintain decreasing order in deque
//             while (!dq.empty() && nums[dq.back()] <= nums[i]) 
//                 dq.pop_back();

//             dq.push_back(i);

//             // Add maximum for the current window
//             if (i >= k - 1) 
//                 ans.push_back(nums[dq.front()]);
//         }
//         return ans;
//     }
// };