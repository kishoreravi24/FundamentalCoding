//serialize code from tree to string
std::string serialize(Node* root){
    std::queue<Node*> q;
    q.push(root);
    std::stringstream ss;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* curr = q.front();
            q.pop();
            
            ss<<curr->data;
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    return ss.str();
}

//deserialize code from string to tree
Node* deserialize(std::vector<std::string> s){
    
    Node* root = new Node(std::stoi(s[0]));
    std::queue<Node*> q;
    q.push(root);
    
    int i=1;
    while(!q.empty()){
        int size = q.size();
        for(int j=0;j<size;j++){
            Node* curr = q.front();
            q.pop();
            
            if(s[i]!='\0'){
                curr->left = new Node(std::stoi(s[i]));
                q.push(curr->left);
                ++i;
            }
            
            if(s[i]!='\0'){
                curr->right = new Node(std::stoi(s[i]));
                q.push(curr->right);
                ++i;
            }
        }
    }
    return root;
}