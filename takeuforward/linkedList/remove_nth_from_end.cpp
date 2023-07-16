class Solution {
public:
    int getCount(ListNode* head,int n){
        int count=1;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = getCount(head,n);
        int counter=0;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* temp = head;
        if(count-1==1){
            return prev;
        }
        count=count-n;
        if(count==1){
            next=head->next;
            head=nullptr;
            head=next;
            return head;
        }
        while(temp!=NULL){
            counter++;
            prev=temp;
            next=temp->next;
            if(counter+1==count){
                std::cout<<counter+1<<" "<<count<<"\n";
                std::cout<<prev->val<<" "<<next->val<<"\n";
                temp=nullptr;
                temp=prev;
                temp->next=next->next;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};