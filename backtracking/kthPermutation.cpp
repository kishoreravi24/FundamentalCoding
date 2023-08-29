#include<bits/stdc++.h>
int getPermute(int n,int k){
	//Find fact and the number in vector
	std::vector<int> nums;
	int fact = 1;
	for(int i=1;i<n;i++){
		fact = fact * i;
		nums.push_back(i);
	}
	nums.push_back(n);

	//reduce k to k-1 because 
	/*
		if n = 4, k = 17 
		1 2 3 4 - 0
		-> we need to find 16
		4 3 2 1 - 17
		
		fact don't find fact for n=4, instead find for n-1 i.e 3
		because, 1 + (2,3,4) , 2 + (1,3,4) , 3 + (1,2,4) , 4 + (1,2,3)

		fact for size(2,3,4) .. = 6
		
		helper string, 16/6 = 2 , so helper = "3"
		erase 3 from nums
		nums = 1 2 4

		// next iteration
		k=k%fact i.e 16%6 = 4
		fact=6/4 = 2

	*/
	std::cout<<"fact "<<fact<<"\n";
	k=k-1;
	std::string helper = "";
	while(true){
		helper = helper + std::to_string(nums[k/fact]);
		nums.erase(nums.begin()+k/fact);
		if(nums.size()==0){
			break;
		}
		k=k%fact;
		fact=fact/nums.size();
	}

	std::cout<<helper;
	return 0;
}
int main(){
	int n,k;
	std::cin>>n>>k;
	getPermute(n,k);
}