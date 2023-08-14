class Solution {
public:
    // Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::unordered_set<int> hash;
        Node* result = head;
        hash.insert(head->data);
        Node* temp = head;

        while (temp->next != nullptr) {
            if (hash.find(temp->next->data) == hash.end()) {
                hash.insert(temp->next->data);
                temp = temp->next;
            } else {
                Node* duplicateNode = temp->next;
                temp->next = duplicateNode->next;
                delete duplicateNode;
            }
        }
        
        return result;
    }
};