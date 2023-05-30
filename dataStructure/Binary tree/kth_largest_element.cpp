// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        //Your code here
            if (root == nullptr) {
        return 0;
    }

    std::vector<int> vect;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        vect.push_back(current->data);

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::sort(vect.begin(),vect.end());
    if (K <= vect.size()) {
        return vect.at(vect.size() - K);
    }
    }
};