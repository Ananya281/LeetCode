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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root==NULL)
        {
            return postorder;
        }
        TreeNode*curr=root;
        while(curr!=NULL)
        {
            if(curr->right==NULL)
            {
                postorder.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                TreeNode*next=curr->right;
                while(next->left!=NULL&&next->left!=curr)
                {
                    next=next->left;
                }
                if(next->left==NULL)
                {
                    next->left=curr;
                    postorder.push_back(curr->val);
                    curr=curr->right;
                }
                else
                {
                    next->left=NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};