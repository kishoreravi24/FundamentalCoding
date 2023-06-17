class DisjointSet{
public:
	int find(std::vector<int>& parent,int index){
		if(parent[index] == -1){
			return index;
		}
		return find(parent,parent[index]);
	}

	void unite(std::vector<int>& parent,std::vector<int>& rank,int graphV,int graphE){
		int s1 = find(parent,graphV);
		int s2 = find(parent,graphE);

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