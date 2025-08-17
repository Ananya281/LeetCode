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
struct Info
{
    bool isbst;
    int minval;
    int maxval;
    int sum;
};
//maxval<root->val<minval
//left             right
int ans=0;
    Info dfs(TreeNode* root)//function with return type struct 
    {
        if(!root)
        {
            return {true,INT_MAX,INT_MIN,0};
        }
        Info left=dfs(root->left);
        Info right=dfs(root->right);
        Info curr;
        curr.isbst=false;
        if(left.isbst && right.isbst && root->val>left.maxval && root->val<right.minval)
        {
            curr.isbst=true;
            curr.minval=min(root->val,left.minval);
            curr.maxval=max(root->val,right.maxval);
            curr.sum=root->val+left.sum+right.sum;
            ans=max(ans,curr.sum);
        }
        else
        {
            curr.isbst=false;
            curr.minval=INT_MIN;
            curr.maxval=INT_MAX;
            curr.sum=0;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);//return object
        //return type ko store ni kia, global update kar dia, vo use kiya fir
        return ans;
    }
};