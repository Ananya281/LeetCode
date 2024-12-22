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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*temp=head;
        ListNode*front=temp->next;
        ListNode*move=front->next;
        temp->next=NULL;
        while(move!=NULL)
        {
            front->next=temp;
            temp=front;
            front=move;
            move=move->next;
        }
        front->next=temp;
        head=front;
        return head;
    }
};