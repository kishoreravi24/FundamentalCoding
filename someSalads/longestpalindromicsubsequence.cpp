#include<bits/stdc++.h>
int lps(int low,int high,std::string s){
	if(low==high){
		return 0;
	}
	if(s[low]==s[high]){
		return 2+lps(low+1,high-1,s);
	}else{
		return std::max(lps(low,high-1,s),lps(low+1,high,s));
	}
}
int main(){
	std::string s="babad";
	int x = lps(0,s.size()-1,s);
	std::cout<<x;
	s = s.substr(0,x);
	std::cout<<"\n"<<s;
	return 0;
}