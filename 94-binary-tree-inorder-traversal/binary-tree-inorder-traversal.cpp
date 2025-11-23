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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }   
        TreeNode* curr=root;
        vector<int>result;
        while(curr)
        {
            if(!curr->left)
            {
                result.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(!prev->right)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return result;
    }
};

//left root right inorder 
//right jane se phle push karna 
//left hat gya root push and go right 


//root left right preorder
//left jane se phle push karna
//left hat gya root ke baad right jana 