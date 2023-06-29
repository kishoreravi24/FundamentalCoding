#include<bits/stdc++.h>
int main(){
	std::list<int> circularList;

	circularList.push_back(5);
	circularList.push_back(6);
	circularList.push_back(7);

    // Manually connect the last node to the first node
	circularList.back() = circularList.front();

	for(auto it:circularList){
		std::cout<<it<<" ";
	}
}