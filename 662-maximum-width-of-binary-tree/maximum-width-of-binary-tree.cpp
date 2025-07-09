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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxi=0;
        while(!q.empty())
        {
            int n=q.size();
            root=q.front().first;
            long long ind=q.front().second;
            long long first;
            long long last;
            for(int i=0;i<n;i++)
            {
                root=q.front().first;
                long long currind=q.front().second-ind;
                q.pop();
                if(i==0)
                {
                    first=currind;
                }
                if(i==n-1)
                {
                    last=currind;
                }
                if(root->left)
                {
                    q.push({root->left,2*currind+1});
                }
                if(root->right)
                {
                    q.push({root->right,2*currind+2});
                }
            }
            maxi=max(maxi,(int)(last-first+1));
        }
        return maxi;
    }
};