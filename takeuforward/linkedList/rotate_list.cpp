class Solution {
public:
    int getHeight(ListNode* head){
        ListNode* temp = head;
        int height=0;
        while(temp!=NULL){
            temp=temp->next;
            height++;
        }
        return height;
    }
    ListNode* getRotate(ListNode* temp){
        ListNode* list = temp;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode* next = temp->next;
        temp->next = NULL;
        ListNode* temp1 = next;
        temp1->next = list;
        return temp1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int height = getHeight(head);
        k=k%height;
        while(k!=0){
            ListNode* temp = head;
            ListNode* rotate = getRotate(temp);
            head = rotate;
            k--;
        }
        return head;
    }
};