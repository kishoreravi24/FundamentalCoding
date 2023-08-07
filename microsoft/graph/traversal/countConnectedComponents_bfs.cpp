#include<bits/stdc++.h>
class Solution{
  public:
    int connectedComponentsCount(int v,std::vector<int> adj[]){
        // BFS
        
        // visited nodes
        std::vector<bool> visited(v,false);
        std::queue<int> q;
        int start = 0;
        q.push(start);
        visited[start]=true;
        int connectedCount = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto vertices:adj[node]){
                if(!visited[vertices]){
                    visited[vertices]=true;
                    q.push(vertices);
                    connectedCount++;
                }
            }
        }
        return connectedCount;
    }
};
int main(){
    int numberOfVertices = 5;
    std::vector<int> adj[numberOfVertices];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    Solution obj;
    int count = obj.connectedComponentsCount(numberOfVertices,adj);
    std::cout<<count<<"\n";
    return 0;
}