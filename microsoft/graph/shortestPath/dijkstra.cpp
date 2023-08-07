class Solution
{
public:
    const int INF = std::numeric_limits<int>::max();
    
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
        vector<int> distance(V, INF); 
        
        distance[S] = 0; // Set distance to source as 0
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjDis = it[1];
                
                if(dis+adjDis < distance[adjNode]){
                    distance[adjNode] = dis + adjDis;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        
        return distance;
    }
};
