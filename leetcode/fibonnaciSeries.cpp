#include<bits/stdc++.h>
int solve(int n){
	if(n<=1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}
int main(){
	int n=6;
	int sum = solve(n);
	std::cout<<sum;
}