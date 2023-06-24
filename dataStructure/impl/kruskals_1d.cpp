#include <vector>
#include <algorithm>

class Edge {
public:
    int src, dest, weight;

    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph {
public:
    std::vector<Edge> edgeList;
    std::vector<int> parent;
    std::vector<int> rank;
    int mst;

    void addEdge(int src, int dest, int weight) {
        Edge edge(src, dest, weight);
        edgeList.push_back(edge);
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class DisjointSet {
public:
    int find(std::vector<int>& parent, int index) {
        if (parent[index] == -1) {
            return index;
        }
        return find(parent, parent[index]);
    }

    void uniteSet(std::vector<int>& parent, std::vector<int>& rank, int graphV, int graphE) {
        int s1 = find(parent, graphV);
        int s2 = find(parent, graphE);

        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
        }
        else if (rank[s1] > rank[s2]) {
            parent[s2] = s1;
        }
        else {
            parent[s2] = s1;
            rank[s1] += 1;
        }
    }
};

int kruskalMST(Graph& graph) {
    int numberOfVertices = graph.parent.size();
    graph.parent.resize(numberOfVertices, -1);
    graph.rank.resize(numberOfVertices, 0);

    std::sort(graph.edgeList.begin(), graph.edgeList.end(), compareEdges);

    DisjointSet disjointSet;
    for (const auto& edge : graph.edgeList) {
        int graphV = edge.src;
        int graphE = edge.dest;
        int graphW = edge.weight;

        if (disjointSet.find(graph.parent, graphV) != disjointSet.find(graph.parent, graphE)) {
            disjointSet.uniteSet(graph.parent, graph.rank, graphV, graphE);
            graph.mst += graphW;
        }
    }

    return graph.mst;
}

int minimumSpanningTree(std::vector<std::vector<int>>& edges, int n) {
    Graph graph;
    for (int i = 0; i < n; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];
        graph.addEdge(src, dest, weight);
    }

    return kruskalMST(graph);
}
