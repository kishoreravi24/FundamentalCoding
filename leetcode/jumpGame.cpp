#include<bits/stdc++.h>
int main(){
	int n;
	std::cin>>n;
	std::vector<int> nums;
	for(int i=0;i<n;i++){
		std::cin>>nums[i];
	}

	//game
	int maxJump = 0;
	for(int i=0;i<n;i++){
		if(i>maxJump){
			std::cout<<"No";
			return 1;
		}
		maxJump = std::max(maxJump,i+nums[i]);
	}
	std::cout<<"Yes";
	return 0;
}