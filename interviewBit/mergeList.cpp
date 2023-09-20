/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* temp;
    if(A->val<B->val){
        temp = A;
        A = A->next;
    }else{
        temp = B;
        B = B->next;
    }
    
    ListNode* list3 = temp;
    while(A!=NULL&&B!=NULL){
        if(A->val<B->val){
            list3->next = A;
            A = A->next;
        }else{
            list3->next = B;
            B = B->next;
        }
        list3 = list3->next;
    }
    if(!A){
        list3->next = B;
    }
    if(!B){
        list3->next = A;
    }
    return temp;
}
