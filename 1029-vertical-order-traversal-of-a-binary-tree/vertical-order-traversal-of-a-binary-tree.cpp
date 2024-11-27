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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            root=p.first;
            int x=p.second.first;
            int y=p.second.second;
            mpp[x][y].insert(root->val);
            if(root->left!=NULL)
            {
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right!=NULL)
            {
                q.push({root->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>result;
        for(auto it:mpp)
        {
            vector<int>ans;
            for(auto ip:it.second)
            {
                ans.insert(ans.end(),ip.second.begin(),ip.second.end());
            }
            result.push_back(ans);
        }
        return result;
    }
};