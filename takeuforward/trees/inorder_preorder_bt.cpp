class Solution {
public:
    TreeNode* helper(int prestart,int instart,int inend,std::vector<int> preorder,std::vector<int> inorder){
        if(prestart>preorder.size()-1||instart>inend){
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[prestart]);

        int index=0;
        for(int i=instart;i<=inend;i++){
            if(inorder[i]==preorder[prestart]){
                index=i;
            }
        }
        
        root->left = helper(prestart+1,instart,index-1,preorder,inorder);
        root->right = helper(prestart+index-instart+1,index+1,inend,preorder,inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0,0,inorder.size()-1,preorder,inorder);
    }
};