#include<bits/stdc++.h>
int binSearch(std::vector<int> nums,int target,int l,int r){
	while(l<=r){
		int mid = l+(r-l)/2;
		// Check target is present at mid
		if(nums[mid]==target){
			return mid;
		}

		// If target is greater, ignore left half
		if(nums[mid]<target){
			l = mid+1;
		}

		// If target is smaller, ignore right half
		if(nums[mid]>target){
			r = mid-1;
		}
	}
	return -1;
}
int main(){
	std::vector<int> nums={-1,0,3,5,9,12};
	int target = 9;
	int size = nums.size();
	int index = binSearch(nums,target,0,size-1);
	std::cout<<index<<" ";
	return 0;
}

