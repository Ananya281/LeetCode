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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        int maxi=arr[n-1];
        vector<int>result;
        result.push_back(maxi);
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=maxi)
            {
                result.push_back(arr[i]);
                maxi=arr[i];
            }
        }
        if(result.empty())
        {
            return NULL;
        }
        reverse(result.begin(),result.end());
        ListNode* newhead=new ListNode(result[0]);
        temp=newhead;
        for(int i=1;i<result.size();i++)
        {
            ListNode*front=new ListNode(result[i]);
            temp->next=front;
            temp=temp->next;
        }
        return newhead;
    }
};