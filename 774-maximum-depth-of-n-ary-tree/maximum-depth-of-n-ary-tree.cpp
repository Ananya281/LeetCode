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
    int maxDepth(Node* root) {
        if(root==NULL)
        {
            return 0;
        }
        int n=root->children.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=maxDepth(root->children[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
        }
        return maxi+1;
    }
};