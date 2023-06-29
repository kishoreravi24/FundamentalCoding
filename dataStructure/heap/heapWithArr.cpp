#include <iostream>

void minHeapify(int arr[], int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] < arr[smallest])
        smallest = leftChild;

    if (rightChild < size && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    if (smallest != index) {
        std::swap(arr[index], arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

//size/2-1

void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(arr, size, i);
}

int extractMin(int arr[], int& size) {
    if (size <= 0)
        return -1; // If heap is empty

    int minValue = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(arr, size, 0);

    return minValue;
}

int main() {
    int arr[] = {10, 5, 2, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Build min heap
    buildMinHeap(arr, size);

    // Accessing the minimum element
    int minValue = arr[0];
    std::cout << "Minimum element: " << minValue << std::endl;

    // Removing the minimum element
    minValue = extractMin(arr, size);
    std::cout << "Removed minimum element: " << minValue << std::endl;

    // Accessing the new minimum element
    minValue = arr[0];
    std::cout << "New minimum element: " << minValue << std::endl;

    return 0;
}


or


Node* convertToMinHeap(const std::vector<int>& elements, int index) {
    if (index >= elements.size())
        return nullptr;

    Node* newNode = new Node(elements[index]);

    newNode->left = convertToMinHeap(elements, 2 * index + 1);
    newNode->right = convertToMinHeap(elements, 2 * index + 2);

    return newNode;
}