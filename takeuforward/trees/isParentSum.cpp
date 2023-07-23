bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL){
        return true;
    }
    if(root->left==NULL&&root->right==NULL){
        return true;
    }
    if(root->left==NULL||root->right==NULL){
        return false;
    }
    return (root->left->data+root->right->data==root->data)&&isParentSum(root->left)&&isParentSum(root->right);
}