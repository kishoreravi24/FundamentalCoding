class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void checkDfs(std::vector<bool> &visited,int &start,std::vector<int> &result,std::vector<int> adj[]){
        result.push_back(start);
        
        for(auto v:adj[start]){
            if(!visited[v]){
                visited[v]=true;
                checkDfs(visited,v,result,adj);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        std::vector<int> result;
        std::vector<bool> visited(V,false);
        int start=0;
        visited[start]=true;
        checkDfs(visited,start,result,adj);
        return result;
    }
};