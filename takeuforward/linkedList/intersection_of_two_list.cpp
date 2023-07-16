class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> hash;
        ListNode* temp = headA;
        while(temp!=NULL){
            hash.insert(temp);
            temp=temp->next;
        }
        ListNode* temp1 = headB;
        while(temp1!=NULL){
            if(hash.find(temp1)!=hash.end()){
                return temp1;
            }
            temp1=temp1->next;
        }
        return NULL;
    }
};