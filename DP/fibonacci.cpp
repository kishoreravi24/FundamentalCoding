#include<bits/stdc++.h>
int fun(int n,std::vector<int> &dp){
	if(n<=1){
		return n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	return dp[n]=fun(n-1,dp)+fun(n-2,dp);
}
int main(){
	int n;
	std::cin>>n;
	std::vector<int> dp(n+1,-1);
	std::cout<<fun(n,dp);
}