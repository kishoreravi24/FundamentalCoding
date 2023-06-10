#include<bits/stdc++.h>
int compare_string(std::string& x,std::string& y){
    //2d vector initialize with zero
    std::vector<std::vector<int>> dp(x.length(),std::vector(y.length(),0));
    int maxLength=0;
    for(int i=0;i<x.length();i++){
        for(int j=i+1;j<y.length();j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else{
                if(x[i]==y[j]){
                    /*
                     dp[i][j] += 1; moves the location not updates the value
                     dp[i][j] = 1; only have value 1
                     dp[i][j] = dp[i-1][j-1]+1; updates the value correctly 
                     
                    */
                    dp[i][j] = dp[i-1][j-1]+1; 
                    maxLength=std::max(maxLength,dp[i][j]);
                }
            }
        }
    }
    return maxLength;
}
int main(){
    std::string x,y;
    std::cin>>x;
    std::cin>>y;
    compare_string(x,y);
}