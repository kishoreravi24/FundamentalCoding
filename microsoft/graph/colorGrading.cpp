#include<bits/stdc++.h>
int main(){
	std::vector<std::vector<int>> adjList = {
		{},
		{2, 5},
        {1, 3, 5},
        {4, 2, 5},
        {3, 5},
        {1, 2, 3, 4}
	};

	int n = adjList.size();
	std::vector<int> color(n,-1);
	color[0]=1;

	for(int i=1;i<n;i++){
		std::unordered_set<int> usedColors;
		for(auto node:adjList[i]){
			if(color[node]!=-1){
				usedColors.insert(color[node]);
			}
		}

		for(int j=1;j<=n;j++){
			if(usedColors.find(j)==usedColors.end()){
				color[i]=j;
				break;
			}
		}
	}

	for(int i=0;i<n;i++){
		std::cout<<color[i]<<" ";
	}
}