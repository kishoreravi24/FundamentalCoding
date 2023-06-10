//Function to check whether there is a subarray present with 0-sum or not.
bool subArrayExists(int arr[], int n)
{
    //Your code here
    int currentSum = 0;
    std::unordered_map<int,int> hash_map;
    for(int i=0;i<n;i++){
        currentSum += arr[i];
        if(currentSum == 0){
            return true;
        }else if(hash_map.find(currentSum)!=hash_map.end()){
            return true;
        }else {
            hash_map[currentSum] = i;
        }
    }
    return false;
}