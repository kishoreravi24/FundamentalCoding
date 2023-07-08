// catalan numbers
#include<bits/stdc++.h>
int main(){
    int n=7;
    std::vector<int> dp(n+1);
    dp[0]=dp[1]=1;
    for(int i=2;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]!=dp[i-j-1]){
                dp[i]+=dp[j]*dp[i-j-1];
            }else{
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
    }
    for(int i=0;i<n;i++){
        std::cout<<dp[i]<<" ";
    }
}