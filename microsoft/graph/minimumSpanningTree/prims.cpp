/* 
minimum spanning tree maeans converting of a graph to a tree, where it have n nodes and n-1 edges
and every node rechable by every other node

*/


#include<bits/stdc++.h>
int spanningTree(int n, vector<vector<int>> adj[]){
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    std::vector<bool> visited(n,false);
    
    pq.push({0,0});
    visited[0]=true;
    int sum=0;
    
    while(!pq.empty()){
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        
        sum+=weight;
        for(auto it:adj[node]){
            int adjNode = it.first;
            int adjWt = it.second;
            if(!visited[adjNode]){
                visited[adjNode]=true;
                pq.push({adjNode,adjWt});
            }
        }
    }
    
    std::cout<<sum;
}
int main(){
    spanningTree(4,___pass adjList___);
}
