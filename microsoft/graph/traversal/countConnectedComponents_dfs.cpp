#include<bits/stdc++.h>
class Solution{
  public:
    void solve(std::vector<bool> &visited,int &start,std::vector<int> adj[],int v,int &count){
        for(auto vertices:adj[start]){
            if(!visited[vertices]){
                visited[vertices]=true;
                count++;
                solve(visited,vertices,adj,v,count);
            }
        }
        return;
    }
    int connectedComponentsCount(int v,std::vector<int> adj[]){
        // Dfs
        
        std::vector<bool> visited(v,false);
        int start = 0;
        visited[start]=true;
        int count = 0;
        solve(visited,start,adj,v,count);
        return count;
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