#include<bits/stdc++.h>

class Edge {
public:
	int src,dest,weight;
};

class Graph {
private:
	std::vector<Edge> edges;
public:
	int V,E;
	Graph(int vertices,int edges){
		V=vertices;
		E=edges;
		edges.resize(E);
	}

	void addEdge(int src,int desc,int weight){
		Edge edge;
		edge.src = src;
		edge.desc = desc;
		edge.weight = weight;
		edges.push_back(edge);
	}
}
int main(){
	int vertices = 4;
	int edges = 5;

	Graph g(v,e);
	g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
}