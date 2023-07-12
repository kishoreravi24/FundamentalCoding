#include<bits/stdc++.h>
int main(){
    int arr[]={4,3,2,1,5};
    int n=5;
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}