#include<bits/stdc++.h>
#define v 5
bool validPath(int i,std::vector<int> path,int graph[][v],int k){
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
bool checkCycle(int k,std::vector<int> &path,int graph[][v]){
    if(k==v){
        // cycle found
        if(graph[path[k-1]][path[0]]==1){
            return true;
        }else{
            return false;
        }
    }
    for(int i=1;i<v;i++){
        if(validPath(i,path,graph,k)){
            path[k]=i;
            if(checkCycle(k+1,path,graph)==true){
                return true;
            }
            path[k]=-1;
        }
    }
    return false;
}
void hamiltonianCycle(int graph[][v]){
    std::vector<int> path(v,-1);
    path[0]=0; //source path
    if(checkCycle(1,path,graph)==false){
        std::cout<<"No hamiltonianCycle path";
        return;
    }
    // print path
    for(auto i:path){
        std::cout<<i<<" ";
    }
    return;
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
	return 0;
}