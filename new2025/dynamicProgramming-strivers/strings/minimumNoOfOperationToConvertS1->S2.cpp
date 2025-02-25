#include<bits/stdc++.h>
int lcs(std::string& s,std::string& t){
	int m = s.size();
	int n = t.size();
	std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}else{
				dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}
int canYouMake(std::string s1,std::string s2){
	return s1.size()+s2.size()-2*lcs(s1,s2);
}