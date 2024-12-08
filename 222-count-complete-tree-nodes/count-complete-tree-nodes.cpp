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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int total=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            total=total+temp.size();
        }
        return total;
    }
};