#include<bits/stdc++.h>
class Solution{
public:
	void dfs(int start,std::vector<int> adj[],std::stack<int> &st,std::vector<bool> &visited){
		visited[start]=true;
		st.push(start);
		for(auto it:adj[start]){
			if(!visited[it]){
				dfs(it,adj,st,visited);
			}
		}
		return;
	}
	void tranposeG(std::vector<std::vector<int>> edges,std::vector<int> &tranpose[]){
		for(auto edge:edges){
			int u = edge[0];
			int v = edge[1];

			tranpose[v].push_back(u);
		}
	}
	void reverseG(int start,std::vector<int> tranpose[],std::vector<int> &result,std::vector<bool> &visited){
		visited[start]=true;
		result.push_back(start);
		for(auto it:adj[start]){
			if(!visited[it]){
				reverseG(it,tranpose,result,visited);
			}
		}
		return;
	}
	void scc(int v,std::vector<int> adj[],std::vector<std::vetor<int>> edges){
		std::vector<bool> visited(v,false);
		std::stack<int> st;
		std::vector<int> result;

		dfs(0,adj,st,visited);

		std::vector<int> tranpose[];
		tranposeG(edges,tranpose);

		visited.assign(v,false);
		while(!st.empty()){
			int u = st.top();
			reverseG(u,tranpose,result,visited);
			st.pop();
		}

		for(auto it:result){
			std::cout<<it<<" ";
		}
		return;
	}
};
int main(){
	std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3},{5,6}};

	std::vector<int> adj[edges.size()];
	//convert edge to adjList
	for(auto it:edges){
		int u = it[0];
		int v = it[1];
		adj[u].push_back(v);
	}

	Solution obj;
	obj.scc(edges.size(),adj,edges);
	return;
}