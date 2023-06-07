//Function to find if there exists a triplet in the 
//array A[] which sums up to X.
bool find3Numbers(int arr[], int n, int X)
{
    //Your Code Here
    for(int i=0;i<n-1;i++){
        std::unordered_set<int> hash_table;
        int target=X-arr[i];
        for(int j=i+1;j<n;j++){
            int curr=target-arr[j];
            if(hash_table.find(curr)!=hash_table.end()){
                return true;
            }else{
                hash_table.insert(arr[j]);
            }
        }
    }
    return false;
}