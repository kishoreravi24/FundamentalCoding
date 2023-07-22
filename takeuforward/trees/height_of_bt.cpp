class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        if(root==NULL){
            return NULL;
        }
        std::queue<Node*> q;
        int height=0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node *curr = q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
            height++;
        }
        return height;
    }
};