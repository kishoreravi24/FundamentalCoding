class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int start,std::vector<bool> &visited,int parent,std::vector<int> adj[]){
        visited[start]=true;
        for(auto it: adj[start]){
            if(!visited[it]){
                if(detectCycle(it,visited,start,adj)){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        std::vector<bool> visited(V,false);
        int parent = -1;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(i,visited,parent,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};