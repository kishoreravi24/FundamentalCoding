#include<bits/stdc++.h>
class Solution{
	Node* reverse(Node* head){
		Node* curr=head;
		Node* prev=NULL;
		Node* next=NULL;
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		return prev;
	}
};