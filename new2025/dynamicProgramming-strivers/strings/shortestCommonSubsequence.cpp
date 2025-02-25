#include<bits/stdc++.h>
std::string scs(std::string s,std::string t){
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

	std::string res = "";
	int i = m,j = n;

	while(i>0&&j>0){
		if(s[i-1]==t[j-1]){
			res+=s[i-1];
			i--;
			j--;
		}else if(dp[i-1][j]>dp[i][j-1]){
			res+=s[i-1];
			i--;
		}else{
			res+=t[j-1];
			j--;
		}
	}

	while(i>0){
		res+=s[i-1];
		i--;
	}

	while(j>0){
		res+=t[j-1];
		j--;
	}
	std::reverse(res.begin(),res.end());
	return res;
}