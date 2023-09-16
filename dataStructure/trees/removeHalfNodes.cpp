/**
binary tree remove half nodes and return final binary tree
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(A==nullptr){
        return nullptr;
    }
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(A->left==nullptr&&A->right!=nullptr){
        TreeNode* temp = A->right;
        delete A;
        return temp;
    }else if(A->right==nullptr&&A->left!=nullptr){
        TreeNode* temp = A->left;
        delete A;
        return temp;
    }
    return A;
}
