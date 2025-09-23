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
    int getheight(TreeNode* root,bool get)
    {
        int height=0;
        if(root==NULL)
        {
            return 0;
        }
        while(root)
        {
            height++;
            if(get==true)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        // int lh=getheight(root,true);
        // int rh=getheight(root,false);
        // if(lh==rh)
        // {
        //     return pow(2,lh)-1;
        // }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};