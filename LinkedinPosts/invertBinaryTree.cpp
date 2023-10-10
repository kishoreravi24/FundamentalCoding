#include<bits/stdc++.h>
class Solution {
public:
  TreeNode* invertBinaryTree(TreeNode* root){
    if(!root){
      return NULL;
    }
    std::swap(root->left,root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    return root;
  }
};
