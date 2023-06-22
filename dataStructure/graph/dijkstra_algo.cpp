std::vector<int> dijkstraAlgo(int V,std::vector<std::vector<int>> adj[],int start){
	//priority_queue
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,greater<std::pair<int,int>>> pq;

	std::vector<int> dist(V,1e9);
	dist[start]=0;
	pq.push({0,start});

	while(!pq.empty()){
		int dis = pq.front().first;
		int node = pq.front().second;

		pq.pop();
		for(auto it: adj[node]){
			int edgeWeight = it[1];
			int adjNode = it[0];

			if(dis+edgeWeight < dist[adjNode]){
				dist[adjNode] = dis+edgeWeight;
				pq.push({dist[adjNode],adjNode});
			}
		}
	}
	return dist;
}