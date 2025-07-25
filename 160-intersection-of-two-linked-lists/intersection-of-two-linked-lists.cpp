/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0;
        int count2=0;
        ListNode* temp=headA;
        while(temp!=NULL)
        {
            count1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL)
        {
            count2++;
            temp=temp->next;
        }
        int diff=count1-count2;
        ListNode* tempA;
        ListNode* tempB;
        tempA=headA;
        tempB=headB;
        if(diff>0)
        {
            while(diff>0)
            {
                diff--;
                tempA=tempA->next;
            }
        }
        else
        {
            diff=abs(diff);
            while(diff>0)
            {
                diff--;
                tempB=tempB->next;
            }
        }
        while(tempA!=NULL && tempB!=NULL)
        {
            if(tempA==tempB)
            {
                return tempA;
            }
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};