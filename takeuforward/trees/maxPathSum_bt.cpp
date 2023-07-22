#include<bits/stdc++.h>
class Solution {
public:
	int sum;
	void checkPath(TreeNode* root){
		if(root==NULL){
			return 0;
		}
		int lh = std::max(0,checkPath(root->left));
		int rh = std::max(0,checkPath(root->right));
		sum = std::max(sum,lh+rh+root->val);
		return std::max(lh,rh)+root->val;
	}
    int maxPathSum(TreeNode* root) {
    	sum=INT_MIN;
    	checkPath(root);
    	return sum;
   	}
};