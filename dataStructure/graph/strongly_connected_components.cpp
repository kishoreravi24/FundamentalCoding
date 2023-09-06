#include<bits/stdc++.h>
void topologicalSort(std::vector<int> adj[],std::vector<bool> &visited,std::stack<int> &st,int start){
    visited[start]=true;
    st.push(start);
    for(auto index:adj[start]){
        if(!visited[index]){
            topologicalSort(adj,visited,st,index);
        }
    }
    
    return;
}
std::vector<std::vector<int>> transposeG(std::vector<std::vector<int>> edges) {
    int V = edges.size();
    std::vector<std::vector<int>> reverseAdj(V);
    for (auto index : edges) {
        int u = index[0];
        int v = index[1];
        reverseAdj[v].push_back(u);
    }
    return reverseAdj;
}
void checkDfs(std::vector<std::vector<int>> &reverseAdj,int start,std::vector<bool> &visited,std::vector<int> &result){
    visited[start]=true;
    result.push_back(start);
    for(auto index:reverseAdj[start]){
        if(!visited[index]){
            checkDfs(reverseAdj,index,visited,result);
        }
    }
    return;
}
int stronglyConnectedComponents(std::vector<std::vector<int>> edges,std::vector<int> adj[]){
    int V = edges.size();
    //Topological sort
    std::vector<bool> visited(V,false);
    std::stack<int> st;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSort(adj,visited,st,i);
        }
    }
    
    //reverseAdj
    std::vector<std::vector<int>> reverseAdj = transposeG(edges);
    
    visited.assign(V,false);
    std::vector<int> result;
    while(!st.empty()){
        int u = st.top();
        if(!visited[u]){
            checkDfs(reverseAdj,u,visited,result);
            for(auto index:result){
                std::cout<<index<<" ";
            }
            result.clear();
        }
        st.pop();
    }
    return 0;
}
int main(){
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3},{5,6}};
    std::vector<int> adj[edges.size()];
    stronglyConnectedComponents(edges,adj);
    return 0;
}