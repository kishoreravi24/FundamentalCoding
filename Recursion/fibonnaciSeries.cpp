// #include<bits/stdc++.h>
// int main(){
// 	int n;
// 	std::cin>>n;
// 	int a = 0,b = 1;
// 	if(n==1){
// 		std::cout<<a;
// 		return 0;
// 	}
// 	if(n==2){
// 		std::cout<<b;
// 		return 0;
// 	}
// 	for(int i=3;i<=n;i++){
// 		int c = a+b;
// 		a=b;
// 		b=c;
// 	}
// 	std::cout<<b;
// 	return 0;
// }

// convert to recursion

#include<bits/stdc++.h>
int fib(int n){
	if(n==1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	return fib(n-1)+fib(n-2);
}
int main(){
	int n;
	std::cin>>n;
	std::cout<<fib(n);
	return 0;
}