class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Define the recursion function with explicit std::function type and [&] capture
        function<int(int, int)> solve = [&](int l, int r){
            if (l == r) return nums[l]; // Base case
            
            int takeLeft = nums[l] - solve(l + 1, r);
            int takeRight = nums[r] - solve(l, r - 1);
            
            return max(takeLeft, takeRight);
        };

        return solve(0, n - 1) >= 0;
    }
};