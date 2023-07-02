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
    
    Node* getHead(){
        return head;
    }
    
};

Node* mergeList(Node* list1,Node* list2){
    if(list1==nullptr){
        return list2;
    }
    
    if(list2==nullptr){
        return list1;
    }
    
    Node* first = nullptr;
    Node* tail = nullptr;
    
    if(list1->data<=list2->data){
        first=list1;
        tail=list1;
        list1=list1->next;
    }else{
        first=list2;
        tail=list2;
        list2=list2->next;
    }
    
    while(list1!=nullptr&&list2!=nullptr){
        if(list1->data<=list2->data){
            tail->next=list1;
            tail=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
    }
    
    if(list1==nullptr){
        tail->next=list2;
    }
    
    if(list2==nullptr){
        tail->next=list1;
    }
    return first;
}

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(6);
    list.insert(7);

    LinkedList list1;
    list1.insert(3);
    list1.insert(9);
    list1.insert(10);

    list.display();

    list1.display();
    
    //Merge two list
    Node* list3 = mergeList(list.getHead(),list1.getHead());
    while(list3!=nullptr){
        std::cout<<list3->data<<" ";
        list3=list3->next;
    }

    return 0;
}