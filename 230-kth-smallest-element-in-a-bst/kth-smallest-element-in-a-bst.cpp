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
    TreeNode* kth(TreeNode* root,int k,int &count)
    {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode*left=kth(root->left,k,count);
        if(left!=NULL)
        {
            return left;
        }
        count++;
        if(count==k)
        {
            return root;
        }
        return kth(root->right,k,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        TreeNode* node=kth(root,k,count);
        return node->val;
    }
};