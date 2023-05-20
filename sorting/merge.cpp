#include<iostream>
void merge(int *arr,int *L, int left,int *R,int right){
    int i,j,k;
    i=j=k=0;
    while(i<left&&j<right){
        if(L[i]<R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }
    while(i<left){
        arr[k++]=L[i++];
    }
    while(j<right){
        arr[k++]=R[j++];
    }
}
void merge_sort(int arr[],int n){
    int mid,i, *L, *R;
    if(n<2){
        return;
    }
    mid=n/2;
    L=(int*)malloc(mid*sizeof(int));
    R=(int*)malloc((n-mid)*sizeof(int));

    for(i=0;i<mid;i++){
        L[i]=arr[i];
    }
    for(i=mid;i<n;i++){
        R[i-mid]=arr[i];
    }
    merge_sort(L,mid);
    merge_sort(R,n-mid);
    merge(arr,L,mid,R,n-mid);
    free(L);
    free(R);

}
int main(){
    int arr[]={30,20,40,10,50};
    merge_sort(arr,5);
    for(int i=0;i<5;i++){
        std::cout<<arr[i];
    }
}