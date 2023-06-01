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

int basic_traversal(Node* root){
    std::queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        std::cout<<current->data<<" ";
        q.pop();
        
        if(current->left!=NULL){
            q.push(current->left);
        }
        
        if(current->right!=NULL){
            q.push(current->right);
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
    
    basic_traversal(root);
    return 0;
}