//sliding window
#include<bits/stdc++.h>
int slidingWindow(int arr[],int k,int size){
    int currSum=0;
    for(int i=0;i<k;i++){
        currSum+=arr[i];
    }
    int maxSum = currSum;
    for(int i=k;i<size;i++){
        std::cout<<i<<" "<<arr[i]<<" "<<(i-k)<<" "<<arr[i-k]<<"\n";
        currSum+=arr[i]-arr[i-k];
        std::cout<<currSum<<"\n";
        if(currSum>maxSum){
            maxSum=currSum;
        }
    }
    return maxSum;
}
int main(){
    int arr[] = {6, 2, -1, 9, 1, -2};
    int k=3;
    int size = (sizeof(arr)/sizeof(arr[0]));
    int res = slidingWindow(arr,k,size);
    std::cout<<"\nResult\n"<<res;
}