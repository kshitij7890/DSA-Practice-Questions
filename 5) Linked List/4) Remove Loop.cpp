//Expected time complexity : O(n)
//Expected auxiliary space : O(1)

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node* head)
{ 
    Node* slow=head;
    Node* fast=head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    
    if(slow!=fast) return;

    slow=head;
    
    while(fast->next!=slow)
    {
        
        slow=slow->next;
        fast=fast->next;
    }
    
    fast->next=NULL;
}