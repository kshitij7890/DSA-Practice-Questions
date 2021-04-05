class Solution
{
public:
    vector<int> levelOrder(Node *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        queue<Node *> q;
        q.push(root);
        while (q.empty() == false)
        {
            Node *curr = q.front();
            q.pop();
            res.push_back(curr->data);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        return res;
    }
};