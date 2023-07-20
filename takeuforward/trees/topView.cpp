void topView(Node * root) {
    std::queue<std::pair<Node*,int>> q;
    std::map<int,int> map;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* curr = it.first;
        int val = it.second;
        
        if(map.find(val)==map.end()){
            map[val]=curr->data;
        }
        if(curr->left!=NULL){
            q.push({curr->left,val-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,val+1});
        }
    }
    for(auto index:map){
        std::cout<<index.second<<" ";
    }
}