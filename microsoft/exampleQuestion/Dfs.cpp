class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void checkDfs(int start,std::vector<bool> &visited,std::vector<int> &res,std::vector<int> adj[]){
        res.push_back(start);
        for(auto it:adj[start]){
            if(!visited[it]){
                visited[it]=true;
                checkDfs(it,visited,res,adj);
            }
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        std::vector<int> res;
        std::vector<bool> visited(V,false);
        int start=0;
        visited[start]=true;
        checkDfs(start,visited,res,adj);
        return res;
    }
};