#include<bits/stdc++.h>
void solve(BinaryTreeNode<int>* root,std::vector<std::string> result,std::string path){
	path+=std::to_string(root->data)+" ";
	if(!root->left&&!root->right){
		result.push_back(path);
		return;
	}
	if(root->left){
		solve(root->left,result,path);
	}
	if(root->right){
		solve(roor->right,result,path);
	}
}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    std::vector<std::string> result;
    std::string path="";
    solve(root,result,path);
}