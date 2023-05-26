#include<bits/stdc++.h>
int main(){
    int arr[5] = {1,2,3,4,5};
    int l = 0, r=5-1;
    while(l<r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
    for(int i=0;i<5;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}