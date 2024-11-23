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
    void getsum(TreeNode*root,int targetsum, vector<int>&arr, vector<vector<int>>&result)
    {
        if(root==NULL)
        {
            return;
        }
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==targetsum)
            {
                result.push_back(arr);
            }
        }
        else
        {
            if(root->left!=NULL)
            {
                getsum(root->left,targetsum-root->val,arr,result);
            }
            if(root->right!=NULL)
            {
                getsum(root->right,targetsum-root->val,arr,result);
            }
        }
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>arr;
        getsum(root,targetSum,arr,result);
        return result;
    }
};