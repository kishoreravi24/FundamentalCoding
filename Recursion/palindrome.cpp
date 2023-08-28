#include<bits/stdc++.h>
bool solve(std::string s,int size,int index){
	if(index==size){
		return true;
	}
	if(s[index]!=s[size-index-1]){
		return false;
	}
	return solve(s,size,index+1);
}
int main(){
	std::string s;
	std::cin>>s;
	int size = s.size();
	if(solve(s,size,0)==0){
		std::cout<<"False";
	}else{
		std::cout<<"True";
	}
	return 0;
}