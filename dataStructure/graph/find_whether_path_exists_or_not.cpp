class Solution {
private:
    std::vector<bool> visited;
public:
    bool checkDfs(int start,int end,std::vector<std::vector<int>>& adj){
        visited[start]=true;
        if(start==end){
            return true;
        }
        for(int i=0;i<adj[start].size();i++){
            if(!visited[adj[start][i]]){
                if(checkDfs(adj[start][i],end,adj)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited.resize(n,false);
        // why adj list eg:
        // Edges: [[0, 1], [1, 2], [2, 3], [3, 0], [2, 4]]
        /*

            Adjacency List:
            0: [1, 3]
            1: [0, 2]
            2: [1, 3, 4]
            3: [2, 0]
            4: [2]

         vertex 0 is adjacent to vertices 1 and 3, so its entry in the adjacency list is [1, 3]. 
         Similarly, vertex 2 is adjacent to vertices 1, 3, and 4, so its entry in the adjacency list is [1, 3, 4].


        */
        std::vector<std::vector<int>> adj(n);
        for(auto& i:edges){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            // why v push to u and u push to v
            /*

            In an undirected graph, an edge between two vertices does not have a specific direction. 
            If there is an edge between vertex u and vertex v, it implies that there is a connection from u to v as well as from v to u. 
            Therefore, when constructing the adjacency list, you need to add both v to the list of neighbors of u and u to the list of neighbors of v.

            */
        }
        return checkDfs(source,destination,adj);
    }
};