#include<stdio.h>
int main(){
    //size of the array
    int n;
    scanf("%d",&n);
    int a[n];
    //Getting array values
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //Getting reverse count;
    int k;
    scanf("%d",&k);
    
    //implementation
    for(int i=0;i<k;i++){
        int x = (k*(i+1))-1;
        printf("%d\n",x);
        if(x<n){
            //reverse logic
            int start=k*i;
            int end=x;
            while(start<end){
                int temp = a[start];
                a[start] = a[end];
                a[end] = temp;
                start++;
                end--;
            }
        }else{
            int start=k*i;
            int end = n-1;
            while(start<end){
                int temp = a[start];
                a[start] = a[end];
                a[end] = temp;
                start++;
                end--;   
            }
            break;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

or


#include<stdio.h>
void reverse(int start,int end,int a[]){
    while(start<end){
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    return;
}
void reverse_count(int a[],int n,int k){
    for(int i=0;i<k;i++){
        int x=(k*(i+1))-1;
        if(x<n){
            reverse(k*i,x,a);
        }else{
            reverse(k*i,n-1,a);
            break;
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    scanf("%d",&k);
    
    reverse_count(a,n,k);
    
    //print
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}