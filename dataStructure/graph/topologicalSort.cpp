//Function to return list containing vertices in Topological order. 
void dfs(std::vector<bool>& visited,int u, std::stack<int>& stack,std::vector<int> adj[]){
    visited[u]=true;
    for(int index:adj[u]){
        if(!visited[index]){
            dfs(visited,index,stack,adj);
        }
    }
    stack.push(u);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    std::vector<bool> visited(V,false);
    std::vector<int> result;
    std::stack<int> stack;
    
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfs(visited,i,stack,adj);
        }
    }
    
    while(!stack.empty()){
        result.push_back(stack.top());
        stack.pop();
    }
    
    return result;
}

/*
no of vertices -> visited(V,false);
traverse vertices
	do normal dfs, but add nodes into stack
stack->vector for result