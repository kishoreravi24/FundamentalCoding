/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
std::vector<TreeNode*> solve(int s,int e){
    std::vector<TreeNode*> res;
    if(s>e){
        return {NULL};
    }
    for(int i=s;i<=e;i++){
        std::vector<TreeNode*> leftSubTree = solve(s,i-1);
        std::vector<TreeNode*> rightSubTree = solve(i+1,e);
        
        for(auto l:leftSubTree){
            for(auto r:rightSubTree){
                TreeNode* newRoot = new TreeNode(i);
                newRoot->left = l;
                newRoot->right = r;
                res.push_back(newRoot);
            }
        }
    }
    return res;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return solve(1,A);
}
