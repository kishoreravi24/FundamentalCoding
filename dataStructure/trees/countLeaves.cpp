int countLeaves(Node* root)
{
  // Your code here
    if(root==0){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return 1;
    }
    
    int lr = countLeaves(root->left);
    int rr = countLeaves(root->right);
    
    return lr+rr;
}