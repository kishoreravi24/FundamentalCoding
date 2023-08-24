#include<bits/stdc++.h>
int main(){
	int n;
	std::cin>>n;
	int prev2 = 0;
	int prev1 = 1;
	for(int i=2;i<=n;i++){
		int curr = prev1+prev2;
		prev2=prev1;
		prev1=curr;
	}
	std::cout<<prev1;
	return 0;
}