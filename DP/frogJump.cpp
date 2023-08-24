#include<bits/stdc++.h>
int jump(std::vector<int> heights,int index,std::vector<int> dp){
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
int frogJump(int n,std::vector<int> heights){
	std::vector<int> dp(n+1,-1);
	int energy = jump(heights,n-1,dp);
	return energy;
}
int frogTabulation(int n,std::vector<int> heights){
	std::vector<int> dp(n,0);
	dp[0]=0;
	for(int i=1;i<n;i++){
		int energy1=dp[i-1]+std::abs(heights[i]-heights[i-1]);
		int energy2=INT_MAX;
		if(i>1){
			energy2=dp[i-2]+std::abs(heights[i]-heights[i-2]);
		}
		dp[i]=std::min(energy1,energy2);
	}
	return dp[n-1];
}
int main(){
	int n;
	std::cin>>n;
	std::vector<int> heights(n);
	for(int i=0;i<n;i++){
		std::cin>>heights[i];
	}

	int energy = frogJump(n,heights);
	int tab = frogTabulation(n,heights);
	std::cout<<energy;
	std::cout<<"\n"<<tab;
	return 0;
}