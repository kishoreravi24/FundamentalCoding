void checkdfs(int V, std::vector<int> adj[],int start){
    if(!visited[start]){
        visited[start]=true;
        result.push_back(start);
        for(int i:adj[start]){
            if(!visited[i]){
                checkdfs(V,adj,i);
            }
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Code here
    int start = 0;
    visited.resize(V,false);
    checkdfs(V,adj,start);
    return result;
}