class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        ListNode* fast = list1;
        ListNode* next1 = NULL;
        ListNode* next2 = NULL;
        while(fast!=NULL&&list2!=NULL){
            next1 = fast->next;
            next2 = list2->next;
            fast->next = list2;
            list2->next = next1;
            fast = next1;
            list2 = next2;
        }
        return list1;
    }
};