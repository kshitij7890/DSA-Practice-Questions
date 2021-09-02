vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int count = q.size();
        vector<int> vec;
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            vec.push_back(curr->data);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        res.push_back(vec);
    }
    return res;
}