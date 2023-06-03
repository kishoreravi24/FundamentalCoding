vector<int> mergeSort(Node* root1,Node* root2){
    std::vector<int> mergeSort;
    if(root1==nullptr&&root2==nullptr){
        return mergeSort;
    }
    inorder(root1,mergeSort);
    inorder(root2,mergeSort);
    std::sort(mergeSort.begin(),mergeSort.end());
    return mergeSort;
}
void inorder(Node* root,std::vector<int> &mergeSort){
    if(root==nullptr){
        return;
    }
    inorder(root->left,mergeSort);
    mergeSort.push_back(root->data);
    inorder(root->right,mergeSort);
}