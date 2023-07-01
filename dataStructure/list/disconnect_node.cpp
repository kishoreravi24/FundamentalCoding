Node* disconnect(Node* head){
	Node* fast = head;
	Node* slow = head;
	Node* prev = nullptr;

	while(fast!=NULL&&fast->next!=NULL){
		prev=slow;
		fast=fast->next->next;
		slow=slow->next;
	}
	prev->next = nullptr;
}

	/*
		4 2 1 5 3
		f=4
		s=4
		p=null

		f=1
		s=2
		prev=null

		f=3
		s=1
		prev=2

		prev origin nullptr, it does not have reference to head , so if prev->next=null, it disconnect the head from 2 , head: 4->2

	*/