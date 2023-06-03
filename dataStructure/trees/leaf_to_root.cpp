// max sum of leaves to root
int sumOfLeaveToRoot(Node* root){
    if(root==NULL){
        return 0;
    }
    
    int leftsubtree = sumOfLeaveToRoot(root->left);
    int rightsubtree = sumOfLeaveToRoot(root->right);
    
    int sumofleavestoroot = root->data+leftsubtree+rightsubtree;
    return root->data+std::max(leftsubtree,rightsubtree);
}