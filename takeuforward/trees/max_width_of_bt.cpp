#include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    	if(root==NULL){
    		return 1;
    	}
    	size_t res = 1;
    	std::queue<std::pair<TreeNode*,size_t>> q;
    	q.push({root,0});
    	while(!q.empty()){
    		int size = q.size();
    		size_t first = q.front().second;
    		size_t second = q.second().second;
    		res = std::max(res,second-first+1);
    		for(int i=0;i<size;i++){
    			TreeNode *curr = q.front().first;
    			size_t curr_id = q.front().second;
    			if(curr->left!=NULL){
    				q.push({curr->left,curr_id*2+1});
    			}
    			if(curr->right!=NULL){
    				q.push({curr->right,curr_id*2+2});
    			}
    		}
    	}
    	return (int)res;
   	}
};