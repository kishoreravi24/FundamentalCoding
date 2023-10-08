#include<bits/stdc++.h>
int lis(std::vector<int> nums,int ind, int prev,std::vector<int> &dp){
	if(ind>=nums.size()){
		return 0;
	}
	if(dp[prev+1]!=-1){
		return dp[prev+1];
	}
	int dont_take = lis(nums,ind+1,prev,dp);
	int take = 1+lis(nums,ind+1,ind,dp);
	if(prev == -1 || nums[ind]>nums[prev]){
		return dp[prev+1]=std::max(take,dont_take);
	}else{
		return dp[prev+1] = dont_take;
	}
	return dp[prev+1];
}
int main(){
	std::vector<int> nums = {0,1,0,3,2,3};
	std::vector<int> dp(nums.size(),-1);
	int n = nums.size();
	int res = lis(nums,0,-1,dp);
	std::cout<<res;
	return 0;
}