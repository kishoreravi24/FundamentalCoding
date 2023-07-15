class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }

        ListNode* first = nullptr;
        if(list1->val>list2->val){
            first=list2;
            list2=list2->next;
        }else{
            first=list1;
            list1=list1->next;
        }
        ListNode* curr = first;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<list2->val){
                curr->next=list1;
                list1=list1->next;
            }else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }

        if(!list1){
            curr->next=list2;
        }
        if(!list2){
            curr->next=list1;
        }
        return first;
    }
};