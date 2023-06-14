class Solution {
private:
    std::vector<int> vect;
public:
    // Return the Kth smallest element in the given BST
    void convertTreeToVect(Node* root) {
        if (root == nullptr) {
            return;
        }
        convertTreeToVect(root->left);
        vect.push_back(root->data);
        convertTreeToVect(root->right);
    }
    
    void heapify(std::vector<int>& vect, int size, int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && vect[leftChild] < vect[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && vect[rightChild] < vect[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(vect[index], vect[smallest]);
            heapify(vect, size, smallest);
        }
    }
    
    void vectToMinHeap() {
        for (int i = vect.size() / 2 - 1; i >= 0; --i) {
            heapify(vect, vect.size(), i);
        }
    }
    
    int KthSmallestElement(Node* root, int K) {
        convertTreeToVect(root);
        vectToMinHeap();
        
        if (K >= 1 && K <= vect.size()) {
            return vect[K - 1];
        }
        
        return -1; // Kth smallest element doesn't exist
    }
};
