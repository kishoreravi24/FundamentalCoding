class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        
        return std::max(lh, rh) + 1;
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        
        return std::max({ld, rd, lh + rh});
    }
};