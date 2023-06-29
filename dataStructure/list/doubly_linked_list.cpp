#include<bits/stdc++.h>
class Node{
public:
	int data;
	Node* prev;
	Node* next;

	Node(int data){
		data = data;
		prev = nullptr;
		next = nullptr;
	}
};
class DoublyLinkedList{
private:
	Node* head;
public:
	DoublyLinkedList(){
		head = nullptr;
	}

	void insertAtBegin(int data){
		Node* newnode = new Node(data);
		if(head==nullptr){
			head=newnode;
			return;
		}
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}

	void insertAtEnd(int data){
		Node* temp = head;
		Node* newnode = new Node(data);
		if(head==NULL){
			head=newnode;
			return;
		}
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = newnode;
		newnode->prev=temp;
	}

	void print(){

	}

	void reversePrint(){

	}
}
int main(){
	DoublyLinkedList list;
	list.insertAtEnd(6);
	list.insertAtEnd(8);
	list.insertAtBegin(2);
	list.insertAtBegin(3);

	print();
	reversePrint();
}