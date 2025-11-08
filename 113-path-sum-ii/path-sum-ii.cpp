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
    void path(TreeNode* root,int targetSum,vector<vector<int>>&result,vector<int>&temp)
    {
        if(root==NULL)
        {
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
        {
            result.push_back(temp);
        }
        else
        {
            path(root->left,targetSum-root->val,result,temp);
            path(root->right,targetSum-root->val,result,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        if(root==NULL)
        {
            return result;
        }
        vector<int>temp;
        path(root,targetSum,result,temp);
        return result;
    }
};