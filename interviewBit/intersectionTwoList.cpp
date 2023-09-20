/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    std::set<ListNode*> hash;
    while(A!=NULL){
        hash.insert(A);
        A=A->next;
    }
    ListNode* temp = B;
    while(temp!=NULL){
        if(hash.find(temp)!=hash.end()){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
