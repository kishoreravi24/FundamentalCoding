class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL){
	        return true;
	    }
	    
        std::queue<Node*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            Node* leftsubtree = q.front();
            q.pop();
            Node* rightsubtree = q.front();
            q.pop();
            
            if(leftsubtree==NULL&&rightsubtree==NULL){
                continue;
            }
            
            if(leftsubtree==NULL||rightsubtree==NULL||leftsubtree->data!=rightsubtree->data){
                return false;
            }
            
            q.push(leftsubtree->left);
            q.push(rightsubtree->right);
            q.push(leftsubtree->right);
            q.push(rightsubtree->left);
        }
        return true;
    }
};