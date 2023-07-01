bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the list
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Push the second half of the list onto a stack
    std::stack<int> stack;
    Node* current = slow->next;

    while (current) {
        stack.push(current->data);
        current = current->next;
    }

    // Compare the values of nodes in the first half with the values popped from the stack
    current = head;

    while (!stack.empty()) {
        if (current->data != stack.top())
            return false;

        stack.pop();
        current = current->next;
    }

    return true;
}