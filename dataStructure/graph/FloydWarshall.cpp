#include<bits/stdc++.h>
#define V 4
#define INF std::numeric_limits<int>::max()

int floydWarshall(int graph[][V]){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(graph[i][k]!=INF&&graph[k][j]!=INF){
				    graph[i][j]=std::min(graph[i][j],graph[i][k]+graph[k][j]);
				}
			}
		}
	}
	return 0;
}
int main(){
    int graph[V][V] = {{0,3,INF,7},
					   {8,0,2,INF},
					   {5,INF,0,1},
					   {2,INF,INF,0}};
 
    // Function call
    floydWarshall(graph);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            std::cout<<graph[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}