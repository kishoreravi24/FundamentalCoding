bool hasCycle(int vertices,std::vector<bool> visited,std::vector<int> adj,std::vector<bool> recursion)
{
	visited[vertices] = true;
	recursion[vertices] = true;

	for(auto neighbor:adj[vertices]){
		if(!visited[neighbor]&&hasCycle(neighbor,visited,adj,recursion)){
			return true;
		}else if(recursion[neighbor]){
			return true;
		}
	}

	recursion[vertices]=false;
	return false;
}
bool detect_cycle(int V,std::vector<int> adj[]){
	std::vector<bool> visited(V,false);
	std::vector<bool> recursion(V,false);

	for(int i=0;i<V;i++){
		if(!visited[i]){
			if(hasCycle(i,visited,adj,recursion));
		}
	}
}