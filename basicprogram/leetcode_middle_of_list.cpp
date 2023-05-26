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
 int getLength(ListNode *node_len){
     int count = 0;
     while(node_len!=NULL){
         count++;
         node_len=node_len->next;
     }
     return count;
 }
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *node_len=head;
        int len=getLength(node_len);
        int count=0;
        while(count<len/2){
            head=head->next;
            count++;
        }
        return head;
    }
};