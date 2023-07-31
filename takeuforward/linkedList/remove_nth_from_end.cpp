/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getHeight(ListNode* temp){
        int height = 0;
        while(temp!=NULL){
            height++;
            temp = temp->next;
        }
        return height;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int height = getHeight(temp);
        int size = height-n;
        if(size == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* result = head;
        ListNode* temp1 = result;
        for(int i=0;i<size-1;i++){
            temp1 = temp1->next;
        }
        ListNode* remove = temp1->next;
        temp1->next = remove->next;
        delete remove;
        return result;
    }
};