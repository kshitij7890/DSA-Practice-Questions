Node* divide(int n, Node *head){
        Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
        for(Node *curr=head;curr!=NULL;curr=curr->next)
        {
            int x=curr->data;
            if(x%2==0)
            {
                if(es==NULL)
                {
                    es=curr;
                    ee=es;
                }
                else{
                    ee->next=curr;
                    ee=ee->next;
                }
            }
            else{
                 if(os==NULL)
                {
                    os=curr;
                    oe=os;
                }
                else{
                    oe->next=curr;
                    oe=oe->next;
                }
            }
        }
        
        if(os==NULL || es==NULL)
        {
            return head;
        }
        ee->next=os;
        oe->next=NULL;
        
        return es;
    }