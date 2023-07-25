class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool hasCycle(int u,std::vector<bool> visited,std::vector<int> adj[],int parent){
        visited[u]=true;
        for(auto neighbor:adj[u]){
            if(!visited[neighbor]){
                if(hasCycle(neighbor,visited,adj,u)){
                    return true;
                }
            }else if(neighbor!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        std::vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(hasCycle(i,visited,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};