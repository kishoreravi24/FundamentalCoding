/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    while(temp!=NULL&&temp->next!=NULL){
        if(temp->val==temp->next->val){
            temp->next = temp->next->next;
            continue;
        }
        temp = temp->next;
    }
    return head;
}
