#include<bits/stdc++.h>
int main(){
	std::vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;

	int low = 0,high=nums.size()-1;

	while(low<=high){
		int mid = low+(high-low)/2;

		if(nums[mid]==target){
			return mid;
		}else if(nums[mid]>=nums[low]){
			if(target>=nums[low]&&target<nums[mid]){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}else{
			if(target>=nums[high]&&target<nums[mid]){
				low=mid+1;
			}else{
				high=mid-1;
			}
		}
	}
	return -1;
}