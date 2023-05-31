int ans = 0;
class bst{
    public:
        int min_val;
        int max_val;
        bool isBst;
        int size;
    
        bst(){
            /*
            The purpose of initializing min_val to INT_MAX and max_val to INT_MIN is to ensure that 
            these values will be updated during the traversal of the binary tree. 
            By setting min_val to INT_MAX, any value encountered during the traversal of the tree
            will be smaller than min_val, and thus, it will be updated accordingly. 
            Similarly, by setting max_val to INT_MIN, any value encountered during the traversal
            will be greater than max_val, and it will be updated accordingly as well.
            */
            min_val = INT_MAX;
            max_val = INT_MIN;
            isBst = true;
            size = 0;
        }
};
class Solution {
public:
    bst checkBst(TreeNode* root) {
        if (root == NULL) {
            return bst();
        }
        
        bst bt;
        //postOrder Traversal
        bst leftsubtree = checkBst(root->left);
        bst rightsubtree = checkBst(root->right);

        //checking false and true condition
        //each node gives values like eg: (10,15,t,2)
        if (leftsubtree.isBst==true && rightsubtree.isBst==true && leftsubtree.max_val <= root->val && rightsubtree.min_val > root->val) {
            bt.isBst = true;
            bt.size = leftsubtree.size + rightsubtree.size + root->val;
            bt.min_val = std::min(root->val, leftsubtree.min_val);
            bt.max_val = std::max(root->val, rightsubtree.max_val);
        } else {
            bt.isBst = false;
            bt.size = std::max(leftsubtree.size, rightsubtree.size);
        }

        ans = std::max(ans, bt.size);
        return bt;
    }
    
    int maxSumBST(TreeNode* root) {
        ans=0;
        checkBst(root);
        return ans;
    }
};