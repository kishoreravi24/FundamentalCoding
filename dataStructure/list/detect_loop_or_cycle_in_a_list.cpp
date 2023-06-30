class Solution
{
    private:
        std::unordered_set<Node*> hash;
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node* fast = head;
        Node* slow = head;

        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                return true;
            }
        }
    }
};