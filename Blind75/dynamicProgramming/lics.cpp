#include<bits/stdc++.h>
int lis(std::vector<int> nums,int prev,int current){
	if(current==nums.size()){
		return 0;
	}

	int take = 0;
	if(nums[current]>prev){
		take=1+lis(nums,nums[current],current+1);
	}
	int notTake = lis(nums,prev,current+1);
	return max(take,notTake);
}
int main(){
	std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	lis(nums,INT_MIN,0);
}