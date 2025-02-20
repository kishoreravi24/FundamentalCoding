#include <bits/stdc++.h> 
int jump(std::vector<int> &heights,int index,std::vector<int> &dp){
	//Base condition
	if(index<=0){
		return 0;
	}

	if(dp[index]!=-1){
		return dp[index];
	}

	//Take i+1 stairs
	int energy1 = jump(heights,index-1,dp)+std::abs(heights[index]-heights[index-1]);
	//Take i+2 stairs
	int energy2 = INT_MAX;
	if(index>1){
		energy2 = jump(heights,index-2,dp)+std::abs(heights[index]-heights[index-2]);
	}

	return dp[index]=std::min(energy1,energy2);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    std::vector<int> dp(n+1,-1);
	int energy = jump(heights,n-1,dp);
	return energy;
}