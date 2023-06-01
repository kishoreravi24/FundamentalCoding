class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        std::queue<TreeNode*> q;
        int check=0;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            std::vector<int> vect;
            check++;

            while(size--){
                TreeNode* current = q.front();
                q.pop();

                //data
                vect.push_back(current->val);

                if(current->left!=NULL){
                    q.push(current->left);
                }

                if(current->right!=NULL){
                    q.push(current->right);
                }
            }

            if(check%2==0)
            std::reverse(vect.begin(),vect.end());
            v.push_back(q);
        }
        return v;
    }
};