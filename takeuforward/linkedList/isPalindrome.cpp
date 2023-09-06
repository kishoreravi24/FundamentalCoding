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
    ListNode* reverse(ListNode* temp){
        ListNode* curr = temp;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int height = getHeight(temp);
        int mid = height/2;
        ListNode* getMid = head;
        while(mid!=0){
            getMid = getMid->next;
            mid--;
        }
        ListNode* revTemp = reverse(getMid);
        getMid->next = NULL;
        ListNode* checkTemp = head;
        while(checkTemp!=NULL&&revTemp!=NULL){
            if(checkTemp->val!=revTemp->val){
                return false;
            }
            checkTemp = checkTemp->next;
            revTemp = revTemp->next;
        }
        return true;
    }
};