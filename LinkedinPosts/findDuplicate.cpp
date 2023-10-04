#include<bits/stdc++.h>
int findDuplicate(std::vector<int> nums){
	int slow = nums[0];
	int fast = nums[0];

	do{
	  slow = nums[slow];
	  fast = nums[nums[fast]];
	}while(slow!=fast);

	fast = nums[0];
	while(fast!=slow){
	 slow = nums[slow];
	 fast = nums[fast];
	}
	return fast;
}
int main(){
	std::vector<int> nums={1,2,3,4,2};
	int index = findDuplicate(nums);
	std::cout<<index<<" ";
	return 0;
}
