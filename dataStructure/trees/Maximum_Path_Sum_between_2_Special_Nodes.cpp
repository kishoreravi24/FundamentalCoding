int utils(Node* root, int& res) {
    if (root == nullptr) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->data;
    }
    
    int lst = utils(root->left, res);
    int rst = utils(root->right, res);
    
    if (root->left != nullptr && root->right != nullptr) {
        res = std::max(res, lst + rst + root->data);
        return root->data + std::max(lst, rst);
    } else {
        if (root->left != nullptr) {
            return lst + root->data;
        } else if (root->right != nullptr) {
            return rst + root->data;
        }
    }
    
    return 0; // Added to handle the case when both left and right child are nullptr
}

int maxPathSumBetweenSpecialNodes(Node* root) {
    int res = INT_MIN;
    int val = utils(root, res);
   
    if (root->left != nullptr && root->right != nullptr) {
        return res;
    } else {
        return std::max(res, val);
    }
}
