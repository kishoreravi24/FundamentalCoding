/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int B) {
    if(!head){
        return NULL;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    int count = 0;
    
    while(curr!=NULL && count<B){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if(next!=NULL){
        head->next = reverseList(next,B);
    }
    
    return prev;
}
