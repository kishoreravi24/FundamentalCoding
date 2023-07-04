#include<bits/stdc++.h>
#define v 5
/*
3 points:
point 1: check all vertices are in path
point 2: if the vertex is already taken,skip that
*/
void displayCycle(std::vector<int> path){
	for(int i=0;i<v;i++){
		std::cout<<path[i]<<" ";
	}
	std::cout<<path[0]<<" ";
	return;
}
bool isValid(int i,int graph[][v],std::vector<int> path,int k){
	if(graph[path[k-1]][i]==0){
		return false;
	}
	for(int j=0;j<k;j++){
		if(path[j]==i){
			return false;
		}
	}
	return true;
}
bool cycleFound(int k,std::vector<int>& path,int graph[][v]){
	//check all vertices are in path
	if(k==v){
		if(graph[path[k-1]][path[0]]==1){
			return true;
		}else{
			return false;
		}
	}

	for(int i=1;i<v;i++){
		if(isValid(i,graph,path,k)){
			path[k]=i;
			if(cycleFound(k+1,path,graph)==true){
				return true;
			}
			path[k]=-1;
		}
	}
	return false;
}
bool hamiltonianCycle(int graph[][v]){
	std::vector<int> path(v,-1);
	path[0]=0; //source starting 0

	if(cycleFound(1,path,graph)==false){
		std::cout<<"NO path"<<" ";
		return false;
	}
	displayCycle(path);
	return true;
	
}
int main(){
	int graph[][v] = {
							   {0, 1, 0, 1, 0},
							   {1, 0, 1, 1, 1},
							   {0, 1, 0, 0, 1},
							   {1, 1, 0, 0, 1},
							   {0, 1, 1, 1, 0},
							};
	hamiltonianCycle(graph);
}