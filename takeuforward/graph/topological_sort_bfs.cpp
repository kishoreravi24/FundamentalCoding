class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    std::vector<int> result;
	    std::vector<int> visited(V,0);
	    std::queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        for(auto u:adj[i]){
	            visited[u]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        result.push_back(u);
	        for(auto v:adj[u]){
	            visited[v]--;
	            if(visited[v]==0){
	                q.push(v);
	            }
	        }
	    }
	    return result;
	}
};