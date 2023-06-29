#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next=newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head=prev;
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(6);
    list.insert(7);

    list.display();

    std::cout<<"\n";
    list.reverse();
    list.display();

    return 0;
}
