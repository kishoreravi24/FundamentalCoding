#include<bits/stdc++.h>
int solve(std::vector<int> nums,int index,std::vector<int> &dp){
	if(index<0){
		return 0;
	}
	if(dp[index]!=-1){
		return dp[index];
	}
	int result = std::max(solve(nums,index-2,dp)+nums[index],solve(nums,index-1,dp));
	dp[index]=result;
	return dp[index];
}
int rob(std::vector<int> nums){
	int index = nums.size();
	std::vector<int> dp(index+1,-1);
	std::cout<<solve(nums,index-1,dp);
	return 0;
}
int robTab(std::vector<int> nums){
    int n = nums.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    }
    std::vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=std::max(nums[0], nums[1]);
    for(int i=2;i<n;i++){
        dp[i] = std::max(dp[i-2]+nums[i],dp[i-1]);
    }
    std::cout<<" "<<dp[n-1];
	return 0;
}
int main(){
	int n;
	std::cin>>n;
	std::vector<int> nums(n);
	for(int i=0;i<n;i++){
		std::cin>>nums[i];
	}
	rob(nums);
	robTab(nums);
	return 0;
}