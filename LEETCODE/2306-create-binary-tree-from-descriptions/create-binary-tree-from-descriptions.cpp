class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> children;
        
        for (auto& it : descriptions) {
            int parentVal = it[0];
            int childVal = it[1];
            int isLeft = it[2];
            
            // 1. Get or create the parent node
            if (mpp.find(parentVal) == mpp.end()) {
                mpp[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parentNode = mpp[parentVal];
            
            // 2. Get or create the child node
            if (mpp.find(childVal) == mpp.end()) {
                mpp[childVal] = new TreeNode(childVal);
            }
            TreeNode* childNode = mpp[childVal];
            
            // 3. Link parent to child
            if (isLeft) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            
            // 4. Track that this node is a child
            children.insert(childVal);
        }
        
        // 5. Find the root (the node that is never a child)
        for (const auto& it : descriptions) {
            int parentVal = it[0];
            if (children.find(parentVal) == children.end()) {
                return mpp[parentVal];
            }
        }
        
        return nullptr;
    }
};