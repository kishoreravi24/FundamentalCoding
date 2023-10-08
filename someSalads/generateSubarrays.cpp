#include<bits/stdc++.h>
void generateSubarrays(std::vector<int> nums,std::vector<int> currentSubarrays,int startIndex){
	if(startIndex == nums.size()){
		for(auto index: currentSubarrays){
			std::cout<<index<<" ";
		}
		std::cout<<"\n";
		return;
	}

	//Include the current element
	currentSubarrays.push_back(nums[startIndex]);
	generateSubarrays(nums,currentSubarrays,startIndex+1);

	//Exclude the current element
	currentSubarrays.pop_back();
	generateSubarrays(nums,currentSubarrays,startIndex+1);
	return;
}
int main(){
	std::vector<int> nums = {1,2,3};
	std::vector<int> currentSubarrays;
	generateSubarrays(nums,currentSubarrays,0);
	return 0;
}