/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        std::vector<int> temp;
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        res.push_back(temp);
    }
    return res;
}
