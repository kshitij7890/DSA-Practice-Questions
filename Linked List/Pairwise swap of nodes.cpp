struct Node* pairwise_swap(struct Node* head)
{
    //manages the overall head
    Node *curr=head->next->next;
    Node *prev=head;
    head =head->next;
    head->next=prev;
    
    while(curr!=NULL && curr->next!=NULL)
    {
        prev->next=curr->next;
        prev=curr;
        Node *nex = curr->next->next;
        curr->next->next =curr;
        curr=nex;
    }
    
    prev->next=curr;
    return head;
    
}