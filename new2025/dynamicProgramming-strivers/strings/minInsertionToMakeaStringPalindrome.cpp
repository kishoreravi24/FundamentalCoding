#include<bits/stdc++.h>
int lcs(std::string& s,std::string& t){
	int m = s.size();
	int n = t.size();
	std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[i-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}
int longestCommonSubsequence(std::string s){
	std::string t = s;
	std::reverse(t.begin(),t.end());
	return lcs(s,t);
}
int minimumInsertions(std::string s){
	return s.size()-longestPalindromicSubsequence(s);
}