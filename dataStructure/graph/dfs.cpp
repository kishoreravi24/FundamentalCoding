std::vector<bool> visited;
std::vector<int> result;

void checkdfs(int start, std::vector<int> adj[]) {
    visited[start] = true;
    result.push_back(start);
    
    for (int i : adj[start]) {
        if (!visited[i]) {
            checkdfs(i, adj);
        }
    }
}

std::vector<int> dfsOfGraph(int V, std::vector<int> adj[]) {
    visited.resize(V, false);
    result.clear(); // Clear the result vector before each DFS traversal
    
    int start = 0;
    checkdfs(start, adj);
    
    return result;
}
