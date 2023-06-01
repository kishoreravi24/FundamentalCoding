class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      std::queue<Node*> q;
      std::vector<int> v;
      q.push(node);
      
      while(!q.empty()){
          Node* current = q.front();
          q.pop();
          v.push_back(current->data);
          
          if(current->left!=NULL){
              q.push(current->left);
          }
          if(current->right!=NULL){
              q.push(current->right);
          }
      }
      return v;
      
    }
};