class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(root==NULL){
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            std::vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr){
                    temp.push_back(curr->val);
                    if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                    if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};