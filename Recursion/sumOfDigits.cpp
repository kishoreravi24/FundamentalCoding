#include<bits/stdc++.h>
int solve(int n){
	if(n==0){
		return 0;
	}
	return solve(n/10)+n%10;
}
int main(){
	int n;
	std::cin>>n;
	std::cout<<solve(n);
}