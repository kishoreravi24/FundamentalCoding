#include<bits/stdc++.h>
int main(){
    int arr[5]={1,4,2,3,0},count=0,target=5;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]+arr[j]==target){
                count++;
            }
        }
    }
    std::cout<<count<<" ";
    return 0;
}