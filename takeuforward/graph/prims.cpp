#include<bits/stdc++.h>

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> q;

    	std::vector<bool> visited(V,false);

    	q.push({0,0});
    	int sum=0;

    	while(!q.empty()){
    		int node = q.top().second;
    		int wt = q.top().first;

    		if(visited[node]==true){
    			continue;
    		}
    		visited[node]=true;

    		sum+=wt;
    		for(auto it:adj[node]){
    			int adjNode = it.first;
    			int adjWt = it.second;

    			if(!visited[adjNode]){
    				q.push({adjWt,adjNode});
    			}
    		}
    	}
    	return sum;
    }
}