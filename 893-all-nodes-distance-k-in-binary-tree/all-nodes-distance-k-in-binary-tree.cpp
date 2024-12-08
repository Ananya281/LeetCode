/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void track(TreeNode* root,map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right)
            {
                q.push(node->right);
                parent[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        track(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*,bool>visited;
        visited[target]=true;
        int distance=0;
        while(!q.empty())
        {
            if(k==distance)
            {
                break;
            }
            else
            {
                distance++;
            }
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(node->left&&!visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right&&!visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node]&&!visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        vector<int>arr;
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            arr.push_back(node->val);
        }
        return arr;
    }
};