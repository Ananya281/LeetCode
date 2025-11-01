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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=head;
        ListNode* pre=dummy;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                pre->next=temp->next;
            }
            else
            {
                pre=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};