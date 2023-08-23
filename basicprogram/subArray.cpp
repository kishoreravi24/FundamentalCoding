#include<bits/stdc++.h>
int main(){
    int arr[] = {1,4,2,3};
    int n = 4;
    
    std::cout<<"subarray\n";
    //subarray : contiguous part of array
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int i=start;i<=end;i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
        }
    }
    
    /*

subarray
1 
1 4 
1 4 2 
1 4 2 3 
4 
4 2 
4 2 3 
2 
2 3 
3 

    */
    
    return 0;
}