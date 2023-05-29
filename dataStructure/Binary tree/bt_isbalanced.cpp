class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int getHeight(Node* node){
        if(node==NULL){
            return 0;
        }
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        return std::max(lh,rh)+1;
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return 0;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if(std::abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right)){
            return 1;
        }else{
            return 0;
        }
    }
};