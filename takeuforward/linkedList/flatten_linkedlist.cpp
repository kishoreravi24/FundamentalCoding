Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	std::vector<int> vect;
	Node* temp = head;
	while(temp!=NULL){
		Node* temp1 = temp;
		while(temp1!=NULL){
			vect.push_back(temp1->data);
			temp1=temp1->child;
		}
		temp = temp->next;
	}

	std::sort(vect.begin(),vect.end());
	Node* ans = new Node(-1);
	Node* res = ans;
	for(int i=0;i<vect.size();i++){
		res->child = new Node(vect[i]);
		res=res->child;
	}
	ans->child->next=NULL;
	return ans->child;
}