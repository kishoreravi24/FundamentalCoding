class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void checkDfs(std::stack<int> &st,int start,std::vector<int> &visited,std::vector<int> adj[]){
		visited[start]=true;
		for(auto v:adj[start]){
			if(!visited[v]){
				checkDfs(st,v,visited,adj);
			}
		}
		st.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
		std::vector<int> result;
		std::vector<bool> visited(V,false);
		std::stack<int> st;

		for(int i=0;i<V;i++){
			if(!visited[i]){
				checkDfs(st,i,visited,adj);
			}
		}

		while(!st.empty()){
			result.push_back(st.top());
			st.pop();
		}

		return result;
	}
};