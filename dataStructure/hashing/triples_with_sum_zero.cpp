class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        for(int i=0;i<n-1;i++){
            std::unordered_set<int> ht;
            for(int j=i+1;j<n;j++){
                int x = -(arr[i]+arr[j]);
                if(ht.find(x)!=ht.end()){
                    return true;
                }else{
                    ht.insert(arr[j]);
                }
            }
        }
        return false;
    }
};