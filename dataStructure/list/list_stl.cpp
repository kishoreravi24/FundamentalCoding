#include<iostream>
#include<list>
int main(){
	std::list<int> list;
	list.push_front(5);
	list.push_front(6);
	list.push_front(7);

	for(auto it:list){
		std::cout<<it<<" ";
	}
	std::cout<<"\n";
	return 0;
}