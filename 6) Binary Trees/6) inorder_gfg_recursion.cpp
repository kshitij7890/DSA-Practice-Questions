void inorder_util(Node *root, vector<int> &arr)
{
    if (root != NULL)
    {
        inorder_util(root->left, arr);
        arr.push_back(root->data);
        inorder_util(root->right, arr);
    }
}

vector<int> inOrder(Node *root)
{
    vector<int> arr;
    inorder_util(root, arr);
    return arr;
}