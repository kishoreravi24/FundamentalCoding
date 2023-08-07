#include<bits/stdc++.h>

class Solution{
public:
    bool hasCycle(std::vector<bool> &visited, std::vector<bool> &recursion, int start, std::vector<int> adj[]){
        visited[start] = true;
        recursion[start] = true;
        
        for(auto neighbor : adj[start]){
            if(!visited[neighbor]){
                if(hasCycle(visited, recursion, neighbor, adj)){
                    return true;
                }   
            } else if(recursion[neighbor]){
                return true;
            }
        }
        
        recursion[start] = false;
        return false;
    }
    
    bool detectCycle(int v, std::vector<int> adj[]){
        std::vector<bool> visited(v, false);
        std::vector<bool> recursion(v, false);
        
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(hasCycle(visited, recursion, i, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n = 4; // Number of nodes
    
    // Define the edges of the graph
    std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}}; // Creating a cycle: 3 -> 0
    
    // Convert edge list to adjacency list
    std::vector<int> adj[n];
    
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        
        adj[u].push_back(v);
    }
    
    Solution obj;
    
    if(obj.detectCycle(n, adj)){
        std::cout << "True";
    } else {
        std::cout << "False";
    }
    
    return 0;
}
