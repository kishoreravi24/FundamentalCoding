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
int function_preorder(Node* root){
    if(root==NULL){
        return 0;
    }
    std::cout<<root->data<<" ";
    function_preorder(root->left);
    function_preorder(root->right);
    return 0;
}

int stack_preorder(Node* root){
    std::stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* current = st.top();
        std::cout<<st.top()->data<<" ";
        st.pop();

        if(current->right!=NULL){
            st.push(current->right);
        }

        if(current->left!=NULL){
            st.push(current->left);
        }
    }

    return 0;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    function_preorder(root);
    std::cout<<"\n";
    stack_preorder(root);
}