#include<bits/stdc++.h>
int solve(std::vector<int> nums){
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
    return dp[n-1];
}
int rob(std::vector<int> nums){
	int index = nums.size();
	if(index==0){
		return 0;
	}else if(index==1){
		return nums[0];
	}
	std::vector<int> temp,temp1;
	for(int i=0;i<index;i++){
		if(i!=0) temp.push_back(nums[i]);
		if(i!=index-1) temp1.push_back(nums[i]);
	}
	int leavingFirstHouse = solve(temp);
	int leavingSecondHouse = solve(temp1);
	return std::max(leavingFirstHouse,leavingSecondHouse);
}
int main(){
	int n;
	std::cin>>n;
	std::vector<int> nums(n);
	for(int i=0;i<n;i++){
		std::cin>>nums[i];
	}
	std::cout<<rob(nums);
}