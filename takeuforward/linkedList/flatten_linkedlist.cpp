Node *flatten(Node *root)
{
   // Your code here
   std::vector<int> vect;
   Node* temp = root;
   while(temp){
       Node* temp1 = temp;
       while(temp1){
           vect.push_back(temp1->data);
           temp1 = temp1->bottom;
       }
       temp = temp->next;
   }
   std::sort(vect.begin(),vect.end());
   Node* res = nullptr;
   Node* tempres = nullptr;
   for(int i=0;i<vect.size();i++){
        if(!res){
            res = new Node(vect[i]);
            tempres = res;
        }else{
            tempres->bottom = new Node(vect[i]);
            tempres = tempres->bottom;
        }
   }
   return res;
}