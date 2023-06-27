class Solution {
public:
    bool helperFunction(TreeNode* l,TreeNode* r){
        if(l==NULL&&r==NULL){
            return true;
        }
        if(l==NULL||r==NULL){
            return false;
        }
        return (l->val==r->val)&&helperFunction(l->left,r->right)&&helperFunction(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return helperFunction(root->left,root->right);
    }
};