#include<bits/stdc++.h>
int main(){
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_front(0);

	for(auto it:list){
		std::cout<<it<<" ";
	}
}