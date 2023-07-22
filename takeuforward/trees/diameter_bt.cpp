class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return std::max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return std::max({ld,rd,lh+rh});
    }
};