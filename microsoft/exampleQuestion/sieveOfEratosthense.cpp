#include<bits/stdc++.h>
int main(){
	//efficient way of finding prime number
	int n=8;
	std::vector<bool> visited(n,true);

	for(int p=2;p*p<=n;p++){
		if(visited[p]){
			for(int i=p*p;i<=n;i+=p){
				visited[i]=false;
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(visited[i]){
			std::cout<<i<<" ";
		}
	}

	return 0;
}