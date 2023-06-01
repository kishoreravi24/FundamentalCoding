class Solution {
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBSTUTIL(Node* root,int minValue, int maxValue){
        if(root==NULL){
            return true;
        }
        if(root->data<=minValue||root->data>=maxValue){
            return false;
        }
        
        return isBSTUTIL(root->left,minValue,root->data)&&isBSTUTIL(root->right,root->data,maxValue);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        return isBSTUTIL(root,INT_MIN,INT_MAX);
    }
};