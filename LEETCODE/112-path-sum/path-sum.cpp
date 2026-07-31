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

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;

        if ( (root->val == targetSum) && root->left == nullptr && root->right == nullptr) return true;
        bool take1 = false, take2 = false;
        if(root->left != nullptr) take1 = hasPathSum(root->left, targetSum-root->val);
        if(root->right != nullptr) take2 = hasPathSum(root->right, targetSum-root->val);
        return take1 || take2;

    }
};