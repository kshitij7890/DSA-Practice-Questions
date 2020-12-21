void preorder_util(Node* root,vector<int> &arr)
{
  if(root!=NULL)
  {
     arr.push_back(root->data);
     preorder_util(root->left,arr);
     preorder_util(root->right,arr);
  }
}


vector <int> preorder(Node* root)
{
   vector<int>arr;
   preorder_util(root,arr);
   return arr;
}