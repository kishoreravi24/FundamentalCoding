void topView(Node* root){
	std::queue<Node* root,int> q;
	std::map<int,Node*> map;
	q.push({root,0});

	while(!q.empty()){
		Node* curr = q.front().first;
		int val = q.front().second;
		q.pop();

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
}