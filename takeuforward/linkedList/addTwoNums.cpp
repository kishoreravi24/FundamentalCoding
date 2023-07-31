class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr; // Initialize head to nullptr
        ListNode* temp = nullptr;
        int c = 0;
        while (c || l1 || l2) {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if(!head){
                head = new ListNode(c%10);
                temp = head;
            }else{
                temp->next = new ListNode(c % 10);
                temp = temp->next;
            }
            c /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
};