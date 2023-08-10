#include<bits/stdc++.h>
class Solution{
    public:
        std::vector<int> prims(int V, vector<vector<int>> adj[], int S){
            std::vector<bool> visited(V,false);
            std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
            pq.push({0,S});
            visited[S]=true;
            int wt = 0;
            while(!pq.empty()){
                int nodeWt = pq.top().first;
                int node = pq.top().second;
                if(visited[node]){
                    continue;
                }
                visited[node]=true;
                pq.pop();
                wt+=nodeWt;
                for(auto it:adj[node]){
                    int adjWt = it[0];
                    int adjNode = it[1];
                    if(!visited[adjNode]){
                        visited[adjNode]=true;
                        pq.push({adjWt,adjNode});
                    }
                }
            }
            return wt;
        }
};