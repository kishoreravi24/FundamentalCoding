vector<int> rightView(Node *root)
{
    // Your Code here
    std::vector<int> q1;
    if (root == NULL)
    {
        return q1;
    }
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            if (i == size - 1)
            {
                q1.push_back(current->data);
            }
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }
    return q1;
}