int intersectPoint(Node* head1, Node* head2)
{
    Node *curr1=head1;
    Node *curr2=head2;
    int c1=0,c2=0;
    for(Node *curr1=head1;curr1!=NULL;curr1=curr1->next)
    {
        c1++;
    }
    
    for(Node *curr2=head2;curr2!=NULL;curr2=curr2->next)
    {
        c2++;
    }
    
    int d=abs(c1-c2);
    
    if(c1>c2)
    {
        for(int i=0;i<d;i++)
        {
            head1=head1->next;
        }
    }
    
    else if(c1<c2)
    {
        for(int i=0;i<d;i++)
        {
            head2=head2->next;
        }
    }
    
   while(head1!=head2)
   {
       head1=head1->next;
       head2=head2->next;
   }
   
   if(head1!=NULL)
   return head1->data; 
   else return -1;
    
}
