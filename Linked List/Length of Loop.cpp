int countNodesinLoop(struct Node *head)
{
    Node *slow=head;
    Node *fast=head->next;
    int count=0;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    
    if(slow!=fast) return 0;
    
    fast=fast->next;
    count=1;
    while(slow!=fast)
    {
        fast=fast->next;
        count++;
    }
    
    
    return count;
    
}