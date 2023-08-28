#include<bits/stdc++.h>
int solve(int n,int a,int b,int c){
	//Boundary condition
	if(n<0){
		return -1;
	}
	//Base condition
	if(n==0){
		return 0;
	}
	int res = std::max(solve(n-a,a,b,c),std::max(solve(n-b,a,b,c),solve(n-c,a,b,c)));
	if(res==-1){
		return -1;
	}
	return res+1;

}
int main(){
	int n;
	std::cin>>n;
	int a,b,c;
	std::cin>>a>>b>>c;
	std::cout<<solve(n,a,b,c);
}