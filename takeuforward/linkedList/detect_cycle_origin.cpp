class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(slow!=head){
                    slow=slow->next;
                    head=head->next;
                }
                return head;
            }
        }
        return NULL;
    }
};

