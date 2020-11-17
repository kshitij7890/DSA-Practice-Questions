void postorder_util(Node*root,vector<int>&arr)
{
    if(root!=NULL)
    {
        postorder_util(root->left,arr);
        postorder_util(root->right,arr);
        arr.push_back(root->data);
    }
}

vector <int> postOrder(Node* root)
{
  vector<int>arr;
  postorder_util(root,arr);
  return arr;
}