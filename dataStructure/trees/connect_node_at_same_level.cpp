class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return nullptr;
        }
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* rightmostNode = nullptr;
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                curr->next = rightmostNode;
                rightmostNode = curr;

                // BFS from right to left
                if (curr->right) {
                    q.push(curr->right);
                }
                if (curr->left) {
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};