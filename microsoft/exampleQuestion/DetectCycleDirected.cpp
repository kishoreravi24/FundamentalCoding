class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectCycle(int start,std::vector<bool> &visited,std::vector<bool> &recursion,std::vector<int> adj[]){
        visited[start]=true;
        recursion[start]=true;
        for(auto it:adj[start]){
            if(!visited[it]){
                if(detectCycle(it,visited,recursion,adj)){
                    return true;
                }
            }else if(recursion[it]){
                return true;
            }
        }
        recursion[start]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        std::vector<bool> visited(V,false);
        std::vector<bool> recursion(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(i,visited,recursion,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};