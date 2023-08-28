#include<bits/stdc++.h>
int fact(int n){
	if(n==1){
		return n;
	}
	return n*fact(n-1);
}
int main(){
	int n;
	std::cin>>n;
	std::cout<<fact(n);
	return 0;
}