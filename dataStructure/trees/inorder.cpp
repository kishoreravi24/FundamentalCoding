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
int function_inorder(Node* root){
    if(root==NULL){
        return 0;
    }
    function_inorder(root->left);
    std::cout<<root->data<<" ";
    function_inorder(root->right);
    return 0;
}

int stack_inorder(Node* root){
    std::stack<Node*> st;
    Node* current = root;
    while(current!=NULL||!st.empty()){
        while(current!=NULL){
            st.push(current);
            current = current->left;
        }
        
        current = st.top();
        st.pop();
        std::cout<<current->data<<" ";
        
        current = current->right;
    }
    return 0;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    function_inorder(root);
    std::cout<<"\n";
    stack_inorder(root);
}