void bottomView(Node* root){
    std::queue<std::pair<Node*,int>> q;
    std::map<int,Node*> map;
    q.push({root,0});

    while(!q.empty()){
        Node* curr = q.front().first;
        mp[q.front().second]=q.front().first;
        int val = q.front().second;
        q.pop();

        if(curr->left!=NULL){
            q.push({curr->left,val-1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,val+1});
        }
    }

    for(auto i=mp.begin();i!=mp.end();i++){
        std::cout<<i->second->data<<" ";
    }
}