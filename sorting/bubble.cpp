#include<iostream>
void bubble_sort(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
              temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;   
            }
        }
    }
}
int main(){
    int arr[]={20,30,40,10,50};
    bubble_sort(arr,5);
    for(int i=0;i<5;i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}