#include<bits/stdc++.h>
class Solution{
public:
	int getHeight(Node* temp){
		int height = 0;
		while(temp!=NULL){
			temp = temp->next;
			height++;
		}
		return height;
	}
	Node* reverse(Node* head){
		Node* temp = head;
		int height = getHeight(temp);
		int mid = height/2;
		while(mid!=0){
			head=head->next;
			mid--;
		}
		return head;
	}
};