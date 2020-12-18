Node *removeDuplicates(Node *root)
{ if(root==NULL) return NULL;
  for(Node *curr=root;curr->next!=NULL;)
  {
      if(curr->next->data==curr->data)
      {
          Node*temp=curr->next;
          curr->next=curr->next->next;
          delete(temp);
      }
      else
      {
          curr=curr->next;
      }
  }
  return root;
}