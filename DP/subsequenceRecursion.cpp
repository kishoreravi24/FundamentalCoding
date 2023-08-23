#include<bits/stdc++.h>
bool subSequence(int arr[],std::vector<int> &res,int n,int index,int sum,int val){
	if(index>=n){
		if(sum==val){
			for(auto it:res){
				std::cout<<it<<" ";
			}
			std::cout<<"\n";
			return true;
		}
		return false;
	}

	sum+=arr[index];
	res.push_back(arr[index]);
	if(subSequence(arr,res,n,index+1,sum,val)==true){
		return true;
	};
	sum-=arr[index];
	res.pop_back();
	if(subSequence(arr,res,n,index+1,sum,val)==true){
		return true;
	}

	return false;
}
int main(){
	// input
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}
	int val;
	std::cin>>val;

	std::vector<int> res;
	subSequence(arr,res,n,0,0,val);
}