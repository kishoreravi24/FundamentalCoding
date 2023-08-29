#include<bits/stdc++.h>
void solve(std::vector<int> &nums,std::vector<std::vector<int>> &res,int index,int size){
	if(index==size){
		res.push_back(nums);
		return;
	}

	for(int i=1;i<=size;i++){
		std::swap(nums[index],nums[i]);
		solve(nums,res,index+1,size);
		std::swap(nums[index],nums[i]);
	}
}
std::vector<std::vector<int>> permutate(std::vector<int> &nums){
	std::vector<std::vector<int>> res;
	int size = nums.size()-1;
	solve(nums,res,0,size);
	return res;
}
int main(){
	std::vector<int> nums = {1,2,3};
	std::vector<std::vector<int>> ans;
	ans = permutate(nums);
	for(auto index:ans){
		for(auto it:index){
			std::cout<<it<<" ";
		}
		std::cout<<"\n";
	}
}