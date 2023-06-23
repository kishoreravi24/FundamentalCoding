#include<iostream>
int main(){
    //with pointer created a heap block memory and adding value to it.
    int *p = (int *)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        std::cin>>p[i];
    }
    std::cout<<p[2]<<"\n";
    int a = 5;
    int *b = &a;
    std::cout<<b<<" "<<*b;
    return 0;
}