#include<bits/stdc++.h>
class Node{
	public:
		int data;
		Node* next;

		Node(int value):data(value),next(nullptr) {}
};

class SinglyLinkedList {
	private:
		Node* head;
	public:
		SinglyLinkedList(){
			head = nullptr;
		}

		void append(int value){
			Node* newNode = new Node(value);
			if(head==nullptr){
				head = newNode;
			}else{
				Node* currHead = head;
				while(currHead->next!=NULL){
					currHead = currHead->next;
				}
				currHead->next = newNode;
			}
		}

		void display(){
		  Node* displayNode = head;
		  while(displayNode!=NULL){
		  	std::cout<<displayNode->data<<" ";
		        displayNode = displayNode->next;
		  }
		}

		
		void clear(){
			while(head!=NULL){
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
};

int main(){
	SinglyLinkedList list;
	list.append(1);
	list.append(2);
	list.append(4);
	list.display();
	list.clear();
	return 0;
}
