class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        std::queue<Node*> q;
        q.push(node);
        int height = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* current = q.front();
                q.pop();
                
                if(current->left !=NULL){
                    q.push(current->left);
                }
                
                if(current->right != NULL){
                    q.push(current->right);
                }
            }
            height++;
        }
        return height;
    }
};

or

int height(struct Node* node){
    if(root==NULL){
        return 0;
    }

    int lh = height(node->left);
    int rh = height(node->right);

    return max(lh,rh)+1;
}