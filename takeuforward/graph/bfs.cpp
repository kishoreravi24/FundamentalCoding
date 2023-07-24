class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        std::vector<bool> visited(V,false);
        std::vector<int> result;
        std::queue<int> q;
        
        int start=0;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        return result;
    }
};