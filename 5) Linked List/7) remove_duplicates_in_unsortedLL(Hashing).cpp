Node * removeDuplicates( Node *head) 
{ 
    unordered_set<int>s;
    struct Node *curr = head; 
    struct Node *prev = NULL; 
    while (curr != NULL) 
    { 
        if (s.find(curr->data) != s.end()) 
        { 
           prev->next = curr->next; 
           delete (curr); 
        } 
        else
        { 
           s.insert(curr->data); 
           prev = curr; 
        } 
        curr = prev->next; 
    } 
    return head;
}