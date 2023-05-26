#include<bits/stdc++.h>
int main(){
    int arr[5] = {1,5,10,15,7};
    int max = arr[0]; // intialize here because if there is one element in array , testcase
    for(int i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    std::cout<<max<<" ";
    return 0;
}