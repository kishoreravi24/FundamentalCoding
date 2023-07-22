class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(root==NULL){
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int size=q.size();
            c++;
            std::vector<int> a;
            for(int i=0;i<size;i++){
                TreeNode *curr = q.front();
                q.pop();
                int val = curr->val;
                a.push_back(val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            if(c%2==0){
                std::reverse(a.begin(),a.end());
            }
            result.push_back(a);
        }
        return result;
    }
};