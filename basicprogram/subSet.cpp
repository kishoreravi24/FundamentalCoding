#include<bits/stdc++.h>
void solve(char input[],int n,std::string res,int index){
    if(index>=n){
        std::cout<<res<<" ";
        std::cout<<"\n";
        return;
    }
    solve(input,n,res,index+1);
    res.push_back(input[index]);
    solve(input,n,res,index+1);
    return;
}
void printSubsequences(char input[]) {
    // Write your code here
    std::string res = "";
    int n = strlen(input);
    solve(input,n,res,0);
}
