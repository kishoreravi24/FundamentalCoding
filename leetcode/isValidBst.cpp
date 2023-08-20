/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        std::queue<std::pair<TreeNode*,std::pair<int,int>>> q;
        q.push({root,{INT_MIN,INT_MAX}});

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int minVal = q.front().second.first;
            int maxVal = q.front().second.second;
            q.pop();

            if(curr->val<=minVal||curr->val>=maxVal){
                return false;
            }

            if(curr->left!=NULL){
                q.push({curr->left,{minVal,curr->val}});
            }
            if(curr->right!=NULL){
                q.push({curr->right,{curr->val,maxVal}});
            }
        }
        return true;
    }
};


//or


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkBst(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL){
            return true;
        }

        if(min!=NULL&&root->val<=min->val){
            return false;
        }

        if(max!=NULL&&root->val>=max->val){
            return false;
        }

        return checkBst(root->left,min,root)&&checkBst(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return checkBst(root,NULL,NULL);
    }
};