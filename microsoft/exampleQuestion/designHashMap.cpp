//Design a data structure that supports insert, delete, search and getRandom in constant time.
#include<bits/stdc++.h>
class Solution{
private:
	std::vector<int> arr;
	std::unordered_map<int,int> hashMap;
public:
	void add(int x){
		if(hashMap.find(x)!=hashMap.end()){
			return;
		}
		arr.push_back(x);
		int size = arr.size();
		hashMap.insert({x,size});
		return;
	}

	void delete(int x){
		if(hashMap.find(x)==hashMap.end()){
			return;
		}
		int index = hashMap.at(x);
		hashMap.erase(x);

		int last = arr.size()-1;
		std::swap(arr[last],arr[index]);
		arr.pop_back();
		hashMap.at(arr[index]) = index;
		return;
	}

	void search(int x){
		if(hashMap.find(x)==hashMap.end()){
			return;
		}
		int index = hashMap.at(x);
		std::cout<<index;
	}
};
int main(){
	Solution obj;
	obj.add()
}