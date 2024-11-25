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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int maxsum=INT_MIN;
        int count=0;
        int maxilevel=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>level;
            count++;
            for(int i=0;i<n;i++)
            {
                root=q.front();
                level.push_back(root->val);
                q.pop();
                if(root->left!=NULL)
                {
                    q.push(root->left);
                }
                if(root->right!=NULL)
                {
                    q.push(root->right);
                }
            }
            int m=level.size();
            int sum=0;
            for(int i=0;i<m;i++)
            {
                sum=sum+level[i];
            }
            if(sum>maxsum)
            {
                maxsum=sum;
                maxilevel=count;
            }
        }
        return maxilevel;
    }
};