#include<bits/stdc++.h>
class MST{
private:
	std::vector<int> mst;
	std::vector<bool> tracker;
	std::vector<int> weight_tracker;
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,greater<std::pair<int,int>>> heap_queue;
public:
	void findMST(std::vector<std::vector<int>> G,int vertices,int edges){

		//starting Vertex
		int startingVertex = 0;

		//storing result of MST
		mst.resize(vertices,0);

		//tracker
		tracker.resize(vertices,false);

		//key
		weight_tracker.resize(vertices,INT_MIN);

		//minHeap for minimum spanning tree
		heap_queue.push(std::make_pair(0,startingVertex));

		while(!heap_queue.empty()){
			int heap_queue_value = heap_queue.top().second;
			heap_queue.pop();

			if(tracker[heap_queue_value]==true){
				continue;
			}

			tracker[heap_queue_value] = true;

			for(int vertex=0;vertex<vertices;vertex++){
				int weight = G[heap_queue_value][vertex];

				if(tracker[vertex]==false&&weight<weight_tracker[vertex]){
					weight_tracker[vertex]=weight;
					heap_queue.push(std::make_pair(weight_tracker[vertex],vertex));
					mst[vertex]=heap_queue_value;
				}
			}
		}
	}

	void printMst(){
		for(auto index:mst){
			std::cout<<index<<" ";
		}
	}
};
int main(){
	std::vector<std::vector<int>> G(6,9);

	// Add edges to the Graph
    G[0][1] = 4;
    G[1][0] = 4;
    G[0][2] = 1;
    G[2][0] = 1;
    G[1][2] = 2;
    G[2][1] = 2;
    G[1][3] = 5;
    G[3][1] = 5;
    G[2][3] = 8;
    G[3][2] = 8;
    G[2][4] = 10;
    G[4][2] = 10;
    G[3][4] = 2;
    G[4][3] = 2;
    G[3][5] = 6;
    G[5][3] = 6;
    G[4][5] = 3;
    G[5][4] = 3;

    MST mst;
    mst.findMst(G,6,9);
    mst.printMst();
}