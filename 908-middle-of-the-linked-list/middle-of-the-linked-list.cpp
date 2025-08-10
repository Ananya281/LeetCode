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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        int mid=count/2;
        temp=head;
        while(mid>0)
        {
            mid--;
            temp=temp->next;
        }
        return temp;
    }
};