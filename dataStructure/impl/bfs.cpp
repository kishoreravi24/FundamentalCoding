#include<btit/stdc++.h>
Class Bfs{
private:
	std::queue<int> queue_pipe;
	std::vector<int> visited;
	std::vector<int> result;
public:
	void bfs(int G[][7],int start,int n){
		visited[start]=1;
		result.push(start);
		queue_pipe.push(start);
		while(!q.empty()){
			int u = q.pop();
			for(int v=1;v<=n;v++){
				if(G[v][7]==1&&visited[v]==0){
					visited[v]=1;
					queue_pipe.push(v);
				}
			}
		}
	}

	void printBfs(){
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
	spanTree.bfs(g,1,7);
	spanTree.printBfs();
	return 0;
}