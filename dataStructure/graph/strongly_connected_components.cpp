#include<bits/stdc++.h>
/*
Strongly connected components
Kosaraju's algorithm
Graph -> adj List -> DFS -> store result in stack -> Transponse a graph -> do dfs with stack on transposed graph -> print the result vect.
*/
void dfs(int start,std::vector<bool>& visited,std::stack<int>& st,std::vector<std::vector<int>>& adj){
	visited[start] = true;
	st.push(start);
	for(int index:adj[start]){
		if(!visited[index]){
			dfs(index,visited,st,adj);
		}
	}
	return;
}
std::vector<std::vector<int>> transposeGraph(std::vector<std::vector<int>> edges){
	std::vector<std::vector<int>> adj(edges.size());
	for(auto index:edges){
		int u = index[0];
		int v = index[1];

		adj[v].push_back(u);
	}
	return adj;
}
std::vector<int> dfsForReverseGraph(int start,std::vector<bool>& visited,std::vector<std::vector<int>>& adj,std::vector<int>& result){
	visited[start]=true;
	result.push_back(start);
	for(auto index:adj[start]){
		if(!visited[start]){
			dfsForReverseGraph(index,visited,adj,result);
		}
	}
	return;
}
void stronglyConnectedComponents(std::vector<std::vector<int>> edges,int v,std::vector<std::vector<int>>& adj){
	std::vector<bool> visited(v,false);
	std::vector<std::vector<int>> reverse_adj;
	std::stack<int> st;
	std::vector<int> result;

	dfs(0,visited,st,adj);
	// while(!st.empty()){
	//     std::cout<<st.top()<<" ";
	//     st.pop();
	// }
	// std::cout<<"\n";

/*
	* so far converted a graph into adjacency List, do a dfs for the list and we have the result in the stack
	* now, transpose the graph and do the dfs for each stack value
*/

	reverse_adj=transposeGraph(edges);
    visited.assign(v, false);
    while(!st.empty()){
    	int u = st.pop();
    	dfsForReverseGraph(u,visited,reverse_adj,result);
    }

    for(auto index: result){
    	std::cout<<index<<" ";
    }

	return;
}
int main(){
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3},{5,6}};
    std::vector<std::vector<int>> adj(edges.size());
    //converting edges into adjacency lists
    for(auto index:edges){
    	int u = index[0];
    	int v = index[1];

    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    stronglyConnectedComponents(edges,edges.size(),adj);
}

//output: 6 5 4 3 2 1 0