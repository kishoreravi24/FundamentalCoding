class Solution{
    public:
    //Function to find the height of a binary tree.
    int recHeight(Node* root){
        if(root==NULL){
            return 0;
        }
        int lh = recHeight(root->left);
        int rh = recHeight(root->right);
        return std::max(lh,rh)+1;
    }
    int height(struct Node* root){
        if(root==NULL){
            return NULL;
        }
        return recHeight(root);
    }
};