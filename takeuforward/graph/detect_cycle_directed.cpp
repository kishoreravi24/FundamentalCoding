#include<bits/stdc++.h>
bool hasCycle(std::vector<bool> &visited,int &start,std::vector<int> adj[],std::vector<bool> &recursion){
    visited[start]=true;
    recursion[start]=true;
    for(auto neighbour:adj[start]){
        if(!visited[neighbour]){
            if(hasCycle(visited,neighbour,adj,recursion)){
                return true;
            }
        }else if(recursion[neighbour]){
            return true;
        }
    }
    return false;
}
bool detect_cycle(int V,std::vector<int> adj[]){
    std::vector<bool> visited(V,false);
    std::vector<bool> recursion(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(hasCycle(visited,i,adj,recursion)){
                return true;
            }
        }   
    }
    return false;
}