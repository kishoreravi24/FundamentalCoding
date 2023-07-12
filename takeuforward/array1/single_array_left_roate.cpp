#include<bits/stdc++.h>
int main(){
    int arr[]={4,3,2,1,5};
    int n=5;
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}