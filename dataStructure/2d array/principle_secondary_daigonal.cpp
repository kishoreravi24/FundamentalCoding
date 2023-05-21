#include<bits/stdc++.h>
int main() {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                std::cout<<a[i][j]<<" ";
            }
        }
        std::cout<<"\n";
    }
    
    //secondary diagonal
    int k=2;
    for(int i=0;i<3;i++){
        std::cout<<a[i][k]<<" ";
        k--;
    }
    
    return 0;
}