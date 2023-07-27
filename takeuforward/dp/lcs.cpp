#include<bits/stdc++.h>
int lcs(int i,int j,std::string text1,std::text2,std::vector<std::vector<int>> &dp){
	if(text1[i]=='\0'||text2=='\0'){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(text1[i]==text2[j]){
		dp[i][j]=1+lcs(i+1,j+1,text1,text2,dp);
	}else{
		dp[i][j]=std::max(lcs(i+1,j,text1,text2,dp),lca(i,j+1,text1,text2,dp));
	}
	return dp[i][j];
}
int longestCommonSubsequence(std::string text1, std::string text2) {
	int m = text1.size();
	int n = text2.size();
	std::vector<std::vector<int>> dp(m+1,std::vector<int>dp(n+1,-1));
	return lcs(0,0,text1,text2,dp);
}