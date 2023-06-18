#include<bits/stdc++.h>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void findLCA(std::list<int> list, Node* root, int n,std::vector<int>& vect) {
    if (root == nullptr)
        return;
    
    if (root->data == n) {
        vect.insert(vect.end(), list.begin(), list.end());
        vect.push_back(n);
    } else {
        list.push_front(root->data);
    }
    
    findLCA(list, root->left, n, vect);
    findLCA(list, root->right, n, vect);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    std::list<int> list;
    std::vector<int> vect;
    findLCA(list, root, 4, vect);
    findLCA(list, root, 7, vect);
    
    for(int i=0;i<vect.size()-1;i++){
        for(int j=i+1;j<vect.size();j++){
            if(vect[i]==vect[j]){
                std::cout<<vect[i]<<" ";
                return 0;
            }
        }
    }

    return 0;
}
