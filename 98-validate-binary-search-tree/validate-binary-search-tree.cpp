#include <limits.h> // For INT_MIN and INT_MAX

class Solution {
public:
    // Helper function to recursively check if the tree is a valid BST
    bool isBSTHelper(TreeNode* root, long long lower, long long upper) {
        if (root == NULL) {
            return true;
        }
        
        // Ensure the current node's value is within the valid range
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        
        // Recursively check the left and right subtrees with updated bounds
        return isBSTHelper(root->left, lower, root->val) && 
               isBSTHelper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        // Initialize the boundaries with INT_MIN and INT_MAX as long values
        return isBSTHelper(root, LONG_MIN, LONG_MAX);
    }
};
