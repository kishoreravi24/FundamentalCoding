#include<bits/stdc++.h>
int main(){
    int arr[4] = {1,5,6,8},max = 0;
    for(int i=0;i<5;i++){
        if(arr[i]%2==0){
            max+=arr[i];
        }
    }
    std::cout<<max<<" ";
    return 0;
}