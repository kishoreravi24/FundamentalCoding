void solve(Node* root,int val,std::vector<int> &result){
    if(root==NULL){
        return;
    }
    if(result.size()==val){
        result.push_back(root->data);
    }
    solve(root->left,val+1,result);
    solve(root->right,val+1,result);
}
vector<int> leftView(Node *root)
{
   // Your code here
   std::vector<int> result;
   solve(root,0,result);
   return result;
}