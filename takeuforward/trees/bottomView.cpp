vector <int> bottomView(Node *root) {
    // Your Code Here
    std::queue<std::pair<Node*,int>> q;
    std::map<int,int> map;
    std::vector<int> result;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* curr = it.first;
        int val = it.second;
        map[val]=curr->data;
        if(curr->left!=NULL){
            q.push({curr->left,val-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,val+1});
        }
    }
    for(auto index:map){
        result.push_back(index.second);
    }
    return result;
}