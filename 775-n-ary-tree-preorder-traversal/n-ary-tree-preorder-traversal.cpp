/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preordertraversal(Node* root, vector<int>&ans)
    {
        if(root==NULL)
        {
            return ans;
        }
        ans.push_back(root->val);
        for(auto it:root->children)
        {
            preordertraversal(it,ans);
        }
        return ans;
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        preordertraversal(root,ans);
        return ans;
    }
};