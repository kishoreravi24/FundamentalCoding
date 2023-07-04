#include<bits/stdc++.h>
void backTrack(std::vector<int>& nums,std::vector<int>& subset,int start){
	for(int num:subset){
		std::cout<<num<<" ";
	}
	std::cout<<"\n";

	for(int i=start;i<nums.size();i++){
		subset.push_back(nums[i]);
		backTrack(nums,subset,i+1);
		subset.pop_back();
	}
}
int main(){
	std::vector<int> nums={1,2,3};
	std::vector<int> subset;
	backTrack(nums,subset,0);
}