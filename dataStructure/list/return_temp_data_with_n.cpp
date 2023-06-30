//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
           //reverse a list
           Node* temp = head;
           Node* next = nullptr;
           Node* prev = nullptr;
           while(temp!=NULL){
              next = temp->next;
              temp->next = prev;
              prev = temp;
              temp = next;
           }
           head=prev;
           
           int count = 0;
           Node* temp1 = head;
           while(temp1!=nullptr){
               count++;
               if(count==n){
                   return temp1->data;
               }
               temp1=temp1->next;
           }
        return -1;
    }
};