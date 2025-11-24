/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* sortlist(ListNode* start, ListNode* end)
{
    if(start==end)//base case
    {
        return NULL;
    }
    //initialise two pointers
    ListNode* slow=start;
    ListNode* fast=start;
    while(fast!=end && fast->next!=end)//find mid
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //slow points to mid
    TreeNode* root=new TreeNode(slow->val);//root bana lia since mid mil gya //0
    root->left=sortlist(start,slow);//left connection
    root->right=sortlist(slow->next,end);//right connection
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        TreeNode* node=sortlist(head,NULL);//start, end
        return node;
    }
};

// list sorted hai, inorder mil jayega
//slow fast pointer se mid find krna, list traverse krna, O(N) time lagega
// tree banega balanced, on every level O(N) total operation
// no of levels=height=logN
// so O(NlogN) total time complexity

//space complexity O(logN) recursion depth auxiliary depth