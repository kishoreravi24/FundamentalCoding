#include<bits/stdc++.h>
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
int function_postorder(Node* root){
    if(root==NULL){
        return 0;
    }

    function_postorder(root->left);
    function_postorder(root->right);
    std::cout<<root->data<<" ";
    return 0;
}

int function_postorder(Node* root){
    if(root==NULL){
        return 0;
    }
    
    std::stack<Node*> st;
    std::stack<int> output;
    
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        output.push(curr->data);
        
        if(curr->left!=NULL){
            st.push(curr->left);
        }
        
        if(curr->right!=NULL){
            st.push(curr->right);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    function_postorder(root);
    std::cout<<"\n";
    stack_preorder(root);
}