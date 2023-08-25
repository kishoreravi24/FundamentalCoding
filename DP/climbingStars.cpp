#include<bits/stdc++.h>
int mod = 1e9+7;
int solve(int n,std::vector<int> &dp){
	if(n==0||n==1){
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	return dp[n] = (solve(n-1,dp)+solve(n-2,dp))%mod;
}
int countDistinctWaysRecursion(int nStairs){
	std::vector<int> dp(nStairs+1,-1);
	return solve(nStairs,dp);
}
int countDistinctWays(int nStairs){
	std::vector<int> dp(nStairs+1,0);
	dp[0]=1;
	dp[1]=2;
	for(int i=2;i<nStairs;i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	return dp[nStairs-1];
}
int main(){
	int n;
	std::cin>>n;
	std::cout<<countDistinctWaysRecursion(n);
	std::cout<<"\n"<<countDistinctWays(n);
}