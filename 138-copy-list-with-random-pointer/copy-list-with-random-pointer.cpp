/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopy(Node* head)
    {
        if(head==NULL)
        {
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
    }
    void connectrandom(Node * head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copy=temp->next;
            if(temp->random!=NULL)
            {
                copy->random=temp->random->next;   
            }
            else
            {
                copy->random=NULL;
            }
            temp=copy->next;
        }
    }
    Node* copy(Node* head)
    {
        Node* dummy=new Node(-1);
        Node* result=dummy;
        Node* temp=head;
        while(temp!=NULL)
        {
            result->next=temp->next;
            result=result->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertcopy(head);
        connectrandom(head);
        return copy(head);
    }
};