class Solution {
public:
    void solve(TreeNode* root,TreeNode* target,std::vector<TreeNode*> &list,std::vector<TreeNode*> path){
        if(root==nullptr){
            return;
        }
        path.push_back(root);
        if(root->val==target->val){
            for(auto index:path){
                list.push_back(index);
            }
            return;
        }
        if(root->left){
            solve(root->left,target,list,path);
        }
        if(root->right){
            solve(root->right,target,list,path);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> listX;
        std::vector<TreeNode*> listY;
        std::unordered_set<std::string> hash;
        std::vector<TreeNode*> pathX;
        std::vector<TreeNode*> pathY;
        solve(root,p,listX,pathX);
        solve(root,q,listY,pathY);
        TreeNode* lca = nullptr;
        for(auto index:listX){
            for(auto index1:listY){
                if(index->val==index1->val){
                    lca = index;
                    break;
                }
            }
        }
        return lca;
    }
};