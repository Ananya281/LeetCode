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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*temp=head;
        ListNode*pre=dummy;
        while(temp!=NULL)
        {
            if(st.find(temp->val)!=st.end())
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