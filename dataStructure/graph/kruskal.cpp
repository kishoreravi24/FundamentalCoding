#include<bits/stdc++.h>

class Edges{
public:
	int vertices,edges,weight;
};

bool compareEdges(const Edges& a, const Edges& b){
	return a.weight < b.weight;
}

class DisjointSet{
public:
	int find(std::vector<int>& parent,int index){
		if(parent[index] == -1){
			return index;
		}
		return find(parent,parent[index]);
	}

	void unite(std::vector<int>& parent,std::vector<int>& rank,int graphV,int graphE){
		int s1 = find(parent,graphV);
		int s2 = find(parent,graphE);

		if(rank[s1]<rank[s2]){
			parent[s1]=s2;
		}else if(rank[s1]>rank[s2]){
			parent[s2]=s1;
		}else{
			parent[s2]=s1;
			rank[s1]+=1;
		}
	}
};

class Graph{
private:
	std::vector<Edges> edgeList;
	std::vector<int> parent;
	std::vector<int> rank;
	int mst=0;
public:
	int vertices,edges;
	Graph(int vertices,int edges){
		this->vertices = vertices;
		this->edges = edges;
	}

	void addEdge(int vertices,int edges,int weight){
		Edges edge;
		edge.vertices = vertices;
		edge.edges = edges;
		edge.weight = weight;
		edgeList.push_back(edge);
	}

	void kruskalMST(){
		//Sorting the graph
		std::sort(edgeList.begin(),edgeList.end(), compareEdges);

		//Parent
		parent.resize(vertices,-1);

		//Rank
		rank.resize(vertices,1);

		//loop
		for(auto list:edgeList){
			int graphV = list.vertices;
			int graphE = list.edges;
			int graphW = list.weight;

			DisjointSet set;
            if(set.find(parent,graphV)!=set.find(parent,graphE)){
                set.unite(parent,rank,graphV,graphE);
                mst+=graphW;
            }
		}
		
		std::cout<<mst<<" ";
	}
};

int main(){
	int vertices = 4;
	int edges = 5;

	Graph g(vertices,edges);
	g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.kruskalMST();
}