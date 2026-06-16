/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n <1) return nullptr;
        
        int div = n/2;
        TreeNode* root = new TreeNode(nums[div]);

        vector<int>left, right;
        for(int i = 0; i<div; i++) left.push_back(nums[i]);
        for(int i = div +1; i<n;i++) right.push_back(nums[i]);

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;

    }
};