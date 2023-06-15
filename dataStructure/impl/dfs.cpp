#include<btit/stdc++.h>
Class Dfs{
private:
	std::vector<int> visited;
	std::vector<int> result;
public:
	void dfs(int G[][7],int start,int n){
		if(visited[start]==0){
			visited[start] = 1;
			result.push(start);
			for(int v=1;v<=n;v++){
				if(G[start][v]==1&&visited[v]==0){
					dfs(v);
				}
			}
		}
	}

	void printDfs(){
		for(auto x: result){
			std::cout<<x<<" ";
		}
	}
};
int main(){

	int G[7][7] = {{0,0,0,0,0,0,0},
				   {0,0,1,1,0,0,0},
				   {0,1,0,0,1,0,0},
				   {0,1,0,0,1,0,0},
				   {0,0,1,1,0,1,1},
				   {0,0,0,0,1,0,0},
				   {0,0,0,0,1,0,0}};
	Bfs spanTree;
	spanTree.dfs(g,1,7);
	spanTree.printDfs();
	return 0;
}