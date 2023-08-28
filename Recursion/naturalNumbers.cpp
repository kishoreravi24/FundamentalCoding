#include<bits/stdc++.h>
int solve(int n){
	if(n==1){
		return 1;
	}
	return n+solve(n-1);
}
int main(){
	int n;
	std::cin>>n;
	std::cout<<solve(n);
	int result = n*(n+1)/2;
	std::cout<<"\n"<<result;
	return 0;
}