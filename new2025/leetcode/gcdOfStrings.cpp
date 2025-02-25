#include<bits/stdc++.h>
class Solution{
public:
	std::string gcdS(std::string s,std::string t){
		if(s+t!=t+s) return "";
		int a = s.size();
		int b = t.size();
		while(b!=0){
			int temp = b;
			b = a%b;
			a = temp;
		}
		return s.substr(0,a);
	}
};