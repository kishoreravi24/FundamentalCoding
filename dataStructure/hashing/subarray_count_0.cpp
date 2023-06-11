//Function to count subarrays with sum equal to 0.
long long int findSubarray(vector<long long int> &arr, int n ) {
    //code here
    std::unordered_map<long long int,long long int> hash_table;
    long long int sum=0;
    long long int count=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            count++;
        }
        if(hash_table.find(sum)!=hash_table.end()){
            count+=hash_table[sum];
        }
        hash_table[sum]++;
    }
    return count;
}