class Solution {
public:
    std::vector<string> ans;
    void path(TreeNode* root,std::string str){
        if(root==NULL){
            return;
        }
        str+=to_string(root->val)+"->";
        if(root->left==NULL&&root->right==NULL){
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
        }
        path(root->left,str);
        path(root->right,str);
        str.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::string str="";
        path(root,str);
        return ans;
    }
};