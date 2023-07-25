class Disjoint{
    public:
        int findParent(std::vector<int> &parent,int index){
            if(parent[index]==-1){
                return index;
            }
            return findParent(parent,parent[index]);
        }
        
        void unite(std::vector<int> &parent,std::vector<int> &rank,int vertices,int edges){
            int s1 = findParent(parent,vertices);
            int s2 = findParent(parent,edges);
            
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
            }else if(rank[s1]>rank[s2]){
                parent[s2]=s1;
            }else{
                parent[s2]=s1;
                rank[s1]+=1;
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        std::vector<std::pair<int,std::pair<int,int>>> edgeList;
        for(int i=0;i<V;i++){
            int vertices;
            int weight;
            for(auto it:adj[i]){
                vertices = it[0];
                weight = it[1];
                edgeList.push_back({weight,{i,vertices}});
            }
        }
        
        std::sort(edgeList.begin(),edgeList.end());
        
        std::vector<int> parent(V,-1);
        std::vector<int> rank(V,1);
        int mst = 0;
        
        for(auto it:edgeList){
            int vertices = it.second.second;
            int edges = it.second.first;
            int weight = it.first;
            
            Disjoint set;
            if(set.findParent(parent,vertices)!=set.findParent(parent,edges)){
                set.unite(parent,rank,vertices,edges);
                mst+=weight;
            }
        }
        
        return mst;
    }
};