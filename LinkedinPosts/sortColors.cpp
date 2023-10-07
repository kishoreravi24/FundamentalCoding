#include<bits/stdc++.h>
int main(){
	std::vector<int> nums = {2,0,2,1,1,0};
	std::vector<int> count(3,0);

	for(int n:nums){
		count[n]++;
	}
	int i=0;
	for(int j=0;j<3;j++){
		while(count[j]--){
			nums[i++]=j;
		}
	}
	return 0;
}
