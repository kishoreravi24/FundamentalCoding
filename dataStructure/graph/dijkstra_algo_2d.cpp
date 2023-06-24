#include<bits/stdc++.h>
#define V 9

const int INF = std::numeric_limits<int>::max();

void dijkstra(std::vector<std::vector<int>>& graph,int source,std::vector<int>& distances){
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
	pq.push(std::make_pair(0,source));

	distances.resize(V,INF);
	distances[source]=0;

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		for(int v=0;v<V;v++){
			if(graph[u][v]!=0&&distances[u]+graph[u][v]<distances[v]){
				distances[v]=distances[u]+graph[u][v];
				pq.push(std::make_pair(distances[v],v));
			}
		}
	}
}

int main(){
    std::vector<std::vector<int>> vect(V,std::vector<int>(V));
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            vect[i][j]=graph[i][j];
        }
    }
    int source = 0;
    std::vector<int> distances;
    dijkstra(vect,source,distances);

    for (int i = 0; i < V; i++) {
        std::cout << i << "\t\t" << distances[i] << std::endl;
    }
}