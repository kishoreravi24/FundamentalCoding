class Solution {
public:
    bool helperFunction(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL){
            return true;
        }
        if(left==NULL||right==NULL){
            return false;
        }
        return (left->val==right->val)&&helperFunction(left->left,right->right)&&helperFunction(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return helperFunction(root->left,root->right);
    }
};