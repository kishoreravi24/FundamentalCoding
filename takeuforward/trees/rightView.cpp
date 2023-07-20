class Solution {
public:
    void solve(TreeNode* root,int val,std::vector<int> &result){
        if(root==NULL){
            return;
        }
        if(result.size()==val){
            result.push_back(root->val);
        }
        solve(root->right,val+1,result);
        solve(root->left,val+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        solve(root,0,result);
        return result;
    }
};