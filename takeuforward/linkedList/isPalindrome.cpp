LinkedListNode<int>* getMid(LinkedListNode<int> *head){
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

LinkedListNode<int> * reverse(LinkedListNode<int> *temp){
    LinkedListNode<int> *curr = temp;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL){
        return true;
    }

    LinkedListNode<int>* mid = getMid(head);
    LinkedListNode<int>* temp1 = mid->next;
    mid->next = reverse(temp1);

    temp1 = head;
    LinkedListNode<int>* temp2 = mid->next;

    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}