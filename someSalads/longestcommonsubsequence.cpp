#include<bits/stdc++.h>
int lcs(int i,int j,std::string s1,std::string s2,std::vector<std::vector<int>> &dp){
	if(s1[i]=='\0'||s2[j]=='\0'){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(s1[i]==s2[j]){
		return dp[i][j]=1+lcs(i+1,j+1,s1,s2,dp);
	}else{
		return dp[i][j]=std::max(lcs(i+1,j,s1,s2,dp),lcs(i,j+1,s1,s2,dp));
	}
	return dp[i][j];
}
int main(){
	std::string s1 = "abcde";
	std::string s2 = "ace";
	std::vector<std::vector<int>> dp(s1.size()+1,std::vector<int>(s2.size()+1,-1));
	int x = lcs(0,0,s1,s2,dp);
	std::cout<<x;
}