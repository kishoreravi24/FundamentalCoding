#include<bits/stdc++.h>
int lps(std::string s,int low,int high,std::vector<std::vector<int>> &dp){
    if(dp[low][high]!=0){
        return dp[low][high];
    }
    if(low==high){
        return 1;
    }
    if(s[low]==s[high]){
        return dp[low][high] = 2+lps(s,low+1,high-1,dp);
    }else{
        return dp[low][high]=std::max(lps(s,low,high-1,dp),lps(s,low+1,high,dp));
    }
    return dp[low][high];
}
int main(){
    std::string s = "babad";
    int m = s.size();
    std::vector<std::vector<int>> dp(m+1,std::vector<int>(m+1,0));
    int n = lps(s,0,m-1,dp);
    s = s.substr(0,n);
    std::cout<<s;
}