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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            ListNode* newhead=head->next;
            return newhead;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};

// list of l nodes
// delete nth node from end that means l-(n-1)th node from start
// when fast is n step ahead of slow, there is n nodes between them 
// both moves together
// fast reach NULL(end) and slow will be at (l-n)th node
// slow->next is target node
// avoids traversal to find length
// O(l) time complexity and O(1) space complexity