class Solution {
public:
    ListNode* getMid(ListNode* temp) {
        ListNode* fast = temp->next;
        ListNode* slow = temp;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode* temp = head;
        ListNode* mid = getMid(temp);
        if(mid==NULL){
            return true;
        }

        ListNode* reverse = mid->next;
        
        // Reverse
        ListNode *next = NULL;
        ListNode *prev = NULL;
        while (reverse) {
            next = reverse->next;
            reverse->next = prev;
            prev = reverse;
            reverse = next;
        }

        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while (temp2 != NULL) {
            if (temp2->val != temp1->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};