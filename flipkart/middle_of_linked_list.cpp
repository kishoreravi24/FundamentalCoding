class Solution {
public:
    int getHeight(ListNode* temp){
        int height=0;
        while(temp!=NULL){
            height++;
            temp=temp->next;
        }
        return height;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int height = getHeight(temp);
        int mid = height/2;
        while(mid!=0){
            head = head->next;
            mid--;
        }
        return head;
    }
};