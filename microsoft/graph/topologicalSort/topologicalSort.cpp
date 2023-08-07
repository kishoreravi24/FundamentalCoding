#include<bits/stdc++.h>
class Solution{
    public:
        void checkDfs(std::vector<int> adj[],std::vector<bool> &visited,int start,std::stack<int> &res){
            visited[start]=true;
            for(auto v:adj[start]){
                if(!visited[v]){
                    checkDfs(adj,visited,v,res);
                }
            }
            
            res.push(start);
        }
        std::vector<int> topologicalSort(int v,std::vector<int> adj[]){
            std::vector<bool> visited(v,false);
            std::stack<int> res;
            std::vector<int> ans;
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    checkDfs(adj,visited,i,res);
                }
            }
            
            while(!res.empty()){
                ans.push_back(res.top());
                res.pop();
            }
            return ans;
        }
};

int main(){
    int numberOfVertices = 4;
    int graph[numberOfVertices][numberOfVertices] = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };
    std::vector<int> adj[numberOfVertices];
    
    for(auto it:graph){
        int u = it[0];
        int v = it[1];
        
        adj[u].push_back(v);
    }
    Solution obj;
    std::vector<int> res = obj.topologicalSort(numberOfVertices,adj);
    for(auto it:res){
        std::cout<<it<<" ";
    }
    return 0;
}