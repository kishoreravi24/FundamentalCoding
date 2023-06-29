#include<iostream>
class Node{
public:
	int data;
	Node* next;

	Node(int value){
		data=value;
		next=nullptr;
	}
};
class CircularLinkedList{
private:
	Node* head;
public:
	CircularLinkedList(){
		head=nullptr;
	}

	void insert(int value){
		Node* newnode = new Node(value);
		if(head==nullptr){
			head=newnode;
			head->next = newnode;
		}else{
			Node* curr = head;
			while(curr->next!=head){
				curr=curr->next;
			}
			curr->next = newnode;
			newnode->next = head;
		}
	}

	void display(){
		Node* curr = head;
		do{
			std::cout<<curr->data<<" ";
			curr = curr->next;
		}while(curr!=head);
	}
};
int main(){
    CircularLinkedList list;

    list.insert(3);
    list.insert(2);
    list.insert(4);
    list.insert(5);

    list.display();
}