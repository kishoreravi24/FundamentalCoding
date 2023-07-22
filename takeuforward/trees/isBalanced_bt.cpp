class Solution {
public:
    int getHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return std::max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return std::abs(lh-rh)<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
};