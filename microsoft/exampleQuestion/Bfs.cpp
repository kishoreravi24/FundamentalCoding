class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        std::queue<int> q;
        std::vector<int> res;
        std::vector<bool> visited(V,false);
        int start=0;
        visited[start]=true;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto it:adj[u]){
               if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
               }
            }
        }
        return res;
    }
};