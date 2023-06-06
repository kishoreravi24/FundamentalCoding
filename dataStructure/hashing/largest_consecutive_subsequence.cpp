//Function to return length of longest subsequence of consecutive integers.
int findLongestConseqSubseq(std::vector<int> arr, int N)
{
    //Your code here
    std::set<int> set(arr.begin(),arr.end());
    int curr = 0;
    int large = 0;
    int min_val = INT_MIN;
    
    for(int x:arr){
        if(x==min_val+1){
            curr++;
        }else{
            curr=1;
        }
        large = std::max(large,curr);
        min_val = x;
    }
    return large;
}