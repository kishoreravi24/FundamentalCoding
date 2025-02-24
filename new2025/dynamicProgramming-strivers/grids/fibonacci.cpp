#include<bits/stdc++.h>
int fib(int n,std::vector<int>& dp){
	if(n<=1){
		return n;
	}else{
		if(dp[n]!=-1){
			return dp[n];
		}else{
			return dp[n] = fib(n-1,dp)+fib(n-2,dp);
		}
	}
}
int main(){
	int n = 5;
	std::vector<int> dp(n+1,-1);
	std::cout<<fib(n,dp);
	return 0;
}

// Tabulation
#include<bits/stdc++.h>
int main(){
	int n = 5;
	std::vector<int> dp(n+1,-1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	std::cout<<dp[n];
}

// Space optimization
#include<bits/stdc++.h>
int main(){
	int n = 5;
	int prev = 0,prev2 = 1;
	for(int i=2;i<=n;i++){
		int curr = prev+prev2;
		prev2=prev;
		prev=curr;
	}
	std::cout<<prev;
	return 0;
}