//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
    std::vector<int> q1;
       if(root==NULL){
           return q1;
       }
   std::queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int size=q.size();
       q1.push_back(q.front()->data);
       
       for(int i=0;i<size;i++){
           Node* current = q.front();
           q.pop();
           
           if(current->left!=NULL){
               q.push(current->left);
           }
           
           if(current->right!=NULL){
               q.push(current->right);
           }
       }
   }
   return q1;
}