class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(!root){
            return result;
        }
        std::queue<std::pair<TreeNode*,int>> q;
        std::map<int,std::multiset<int>> map;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front().first;
                int val = q.front().second;
                if(curr){
                    //curr->val
                    map[val].insert(curr->val);
                    q.pop();
                    if(curr->left!=NULL){
                        q.push({curr->left,val-1});
                    }
                    if(curr->right!=NULL){
                        q.push({curr->right,val+1});
                    }
                }
            }
        }
        for(auto index:map){
            result.push_back(std::vector<int>(index.second.rbegin(),index.second.rend()));
        }
        return result;
    }
};