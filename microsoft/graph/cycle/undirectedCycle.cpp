#include<bits/stdc++.h>
class Solution{
  public:
    bool hasCycle(std::vector<int> adj[],int start,std::vector<bool> &visited,int parent){
        visited[start]=true;
        for(auto it:adj[start]){
            if(!visited[it]){
                if(hasCycle(adj,it,visited,parent)){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool detectCycle(int v,std::vector<int> adj[]){
        std::vector<bool> visited(v,false);
        int parent = -1;
        for(int i=0;i<v;i++){
            if(hasCycle(adj,i,visited,parent)){
                return true;
            }
        }
        return false;
    }
};
int main(){
    int n=4;
    std::vector<std::pair<int,int>> graph = {{0,1},{1,0},{1,2},{2,1},{2,3},{3,2},{3,0},{0,3}};
    
    std::vector<int> adj[n];
    //convert
    for(auto it:graph){
        int u = it.first;
        int v = it.second;
        
        adj[u].push_back(v);
    }
    
    Solution obj;
    if(obj.detectCycle(n,adj)){
        std::cout<<"True";
    }else{
        std::cout<<"False";
    }
    return 0;
    
}