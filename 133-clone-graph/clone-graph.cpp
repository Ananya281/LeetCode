/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,Node* clonenode,unordered_map<Node*,Node*>&mpp)
    {
        for(auto it:node->neighbors)
        {
            if(mpp.find(it)==mpp.end())
            {
                Node* clone=new Node(it->val);
                mpp[it]=clone;
                clonenode->neighbors.push_back(clone);
                dfs(it,clone,mpp);
            }
            else
            {
                clonenode->neighbors.push_back(mpp[it]);   
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        unordered_map<Node*,Node*>mpp;
        Node* clonenode=new Node(node->val);
        mpp[node]=clonenode;
        dfs(node,clonenode,mpp);
        return clonenode;
    }
};