/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int getHeight(ListNode* temp){
     int height = 0;
     while(temp!=NULL){
         height++;
         temp = temp->next;
     }
     return height;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* temp = A;
    int height = getHeight(temp);
    int mid = height-B-1;
    if(mid<0){
        ListNode* newhead = A->next;
        delete A;
        return newhead;
    }
    ListNode* traverseList = A;
    while(mid>0){
        traverseList = traverseList->next;
        mid--;
    }
    ListNode* removal = traverseList->next;
    traverseList->next = removal->next;
    delete removal;
    return A;
}
