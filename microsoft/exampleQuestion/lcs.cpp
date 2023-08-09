#include<bits/stdc++.h>
int lcs1(std::string s1,std::string s2,int m,int n){
	//normal dynamic programming with recursion
	if(m==0||n==0){
		return 0;
	}
	if(s1[m-1]==s2[n-1]){
		return 1+lcs1(s1,s2,m-1,n-1);
	}else{
		return std::max(lcs1(s1,s2,m-1,n),lcs1(s1,s2,m,n-1));
	}
}
int lsc2(std::string s1,std::string s2,int m,int n,std::vector<std::vector<int>> &dp){
	// dynamic programming with recursion and memoization
	if(m==0||n==0){
		return 0;
	}
	if(s1[m-1]==s2[n-1]){
		return dp[m][n]=1+lcs2(s1,s2,m-1,n-1,dp);
	}
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	return dp[m][n]=std::max(lcs2(s1,s2,m-1,n,dp),lcs(s1,s2,m,n-1,dp));
}
int tabulation(std::string s1,std::string s2,int m,int n,std::vetor<std::vector<int>> &tab){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				tab[i][j]=0;
			}else if(s1[i-1]==s2[j-1]){
				tab[i][j]=1+tab[i-1][j-1];
			}else{
				tab[i][j] = std::max(tab[i-1][j],tab[i][j-1]);
			}
		}
	}
	return tab[m][n];
}
int main(){
	std::string s1 = "AGGTAB";
	std::string s2 = "GXTXAYB";

	int m = s1.size();
	int n = s2.size();
	std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,-1));
	std::cout<<lcs1(s1,s2,m,n);
	std::cout<<lcs2(s1,s2,m,n,dp);

	// Tabulation method

	std::vector<std::vector<int>> tab(m+1,std::vector<int>(n+1,0));
	std::cout<<tabulation(s1,s2,m,n,tab);
}