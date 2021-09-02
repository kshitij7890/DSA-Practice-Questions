class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node *reverse(Node *head)
    {
        Node*curr = head;
        Node*prev = NULL;
        
        while(curr!=NULL)
        {
            Node*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }
    
    bool isPalindrome(Node *head)
    {
        //finding middle
        if(head==NULL) return true;
        Node*slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reversing second half
        Node *rev=reverse(slow->next);
        
        //traversing and comparing both
        Node *curr=head;
        while (rev!=NULL)
        {
            if(curr->data!=rev->data) return false;
            else{
                curr=curr->next;
                rev=rev->next;
            }
        }
        
        return true;
        
        
    }
    
};