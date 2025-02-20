#include<bits/stdc++.h>
int f(int i,int n,std::vector<int>& price,std::vector<std::vector<int>>& dp){
	if(i==0){
		return n*price[0];
	}

	if(dp[i][n]!=-1){
		return dp[i][n];
	}

	int notTake = f(i-1,n,price,dp);
	int take = INT_MIN;
	int rodLen = i+1;
	if(rodLen<=n) take = price[i]+f(i,n-rodLen,price,dp);
	return dp[i][n]=std::max(take,notTake);
}


int cutRod(vector<int> &price, int n)
{
	std::vector<std::vector<int>> dp(n,std::vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}


// Tabulation

int cutRod(vector<int> &price, int n)
{
	std::vector<std::vector<int>> dp(n,std::vector<int>(n+1,0));
	
	for(int i=0;i<=n;i++){
		dp[0][i] = i*price[0];
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			int notTake = dp[i-1][j];
			int take = INT_MIN;
			int rodLen = i+1;
			if(rodLen<=j) take = price[i]+dp[i][j-rodLen];
			dp[i][j]=std::max(take,notTake);
		}
	}

	return dp[n-1][n];
}


// Space optimization


int cutRod(vector<int> &price, int n)
{
	std::vector<int> prev(n+1,0);
	std::vector<int> curr(n+1,0);
	
	for(int i=0;i<=n;i++){
		prev[i] = i*price[0];
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			int notTake = prev[j];
			int take = INT_MIN;
			int rodLen = i+1;
			if(rodLen<=j) take = price[i]+curr[j-rodLen];
			curr[j]=std::max(take,notTake);
		}
		prev = curr;
	}

	return prev[n];
}