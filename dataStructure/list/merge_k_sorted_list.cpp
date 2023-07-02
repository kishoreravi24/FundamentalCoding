class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeList(Node* list1,Node* list2){
        if(list1==nullptr){
            list1=list1->next;
        }
        
        if(list2==nullptr){
            list2=list2->next;
        }
        
        Node* first = nullptr;
        Node* tail = nullptr;
        
        if(list1->data<=list2->data){
            first = list1;
            tail = list1;
            list1 = list1->next;
        }else{
            first = list2;
            tail = list2;
            list2 = list2->next;
        }
        
        
        //mergeList
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->data<=list2->data){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        
        if(list1==nullptr){
            tail->next = list2;
        }
        
        if(list2 == nullptr){
            tail->next = list1;
        }
        
        return first;
    }
    Node* mergeKLists(Node *arr[], int K)
    {
           // Your code here
           /*
           merging first two list then return the merge list then merge with another..
           
           */
           if(K==1){
               Node* list = arr[0];
               return list;
           }
           
           Node* list = mergeList(arr[0],arr[1]);
           if(K>=2){
               for(int i=2;i<K;i++){
                    list = mergeList(list,arr[i]);
               }
           }
            return list;
    }
};