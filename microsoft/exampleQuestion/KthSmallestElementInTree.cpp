class Solution {
public:
    void traverse(TreeNode* root,std::vector<int> &res){
        if(root==NULL){
            return;
        }
        traverse(root->left,res);
        res.push_back(root->val);
        traverse(root->right,res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = root;
        std::vector<int> res;
        traverse(temp,res);
        return res[k-1];
    }
};