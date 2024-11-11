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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int left=1+maxDepth(root->left);
        int right=1+maxDepth(root->right);
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        if(abs(left-right)>1)
        {
            return false;
        }
        bool leftnode=isBalanced(root->left);
        bool rightnode=isBalanced(root->right);
        if(!leftnode || !rightnode)
        {
            return false;
        }
        return true;
    }
};