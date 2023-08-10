#include<bits/stdc++.h>
int main(){
	int arr[]={2, 1, 5, 1, 3, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k=3;
	int curr_sum=0;
	for(int i=0;i<k;i++){
		curr_sum+=arr[i];
	}
	int max_sum = curr_sum;
	for(int i=k;i<size;i++){
		curr_sum+=arr[i]-arr[i-k];
		max_sum = std::max(curr_sum,max_sum);
	}
	std::cout<<max_sum;
	return 0;
}