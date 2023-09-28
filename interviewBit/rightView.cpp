/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    std::vector<int> res;
    std::queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            if(i==size-1){
                res.push_back(curr->val);
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return res;
}
