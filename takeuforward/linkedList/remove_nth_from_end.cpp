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
            temp = temp->next;
            height++;
        }
        return height;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int height = getHeight(temp);
        int removal = height-n-1;
        
        if (removal < 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* removalList = head;
        
        while(removal>0){
            removalList = removalList->next;
            removal--;
        }
        ListNode* removeNext = removalList->next;
        removalList->next = removeNext->next;
        delete removeNext;
        return head;
    }
};};