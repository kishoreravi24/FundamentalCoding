#include<bits/stdc++.h>
void findPath(std::vector<std::vector<int>> m,int n,std::vector<std::vector<bool>> &visited,std::vector<std::string> &result,std::string &path,int &row,int &col){
	if(row==n-1&&col==n-1){
		result.push_back(path);
		return;
	}
	visited[row][col]=true;
	if(row-1>=0&&m[row-1][col]==1&&!visited[row-1][col]){
		findPath(m,n,visited,result,path+"U",row-1,col);
		visited[row-1][col]=false;
	}

	if(row+1<n&&m[row+1][col]==1&&!visited[row+1][col]){
		findPath(m,n,visited,result,path+"D",row+1,col);
		visited[row+1][col]=false;
	}

	if(col-1>=0&&m[row][col-1]==1&&!visited[row][col-1]){
		findPath(m,n,visited,result,path+"L",row,col-1);
		visited[row][col-1]=false;
	}

	if(col+1<n&&m[row][col+1]==1&&!visited[row][col+1]){
		findPath(m,n,visited,result,path+"R",row,col+1);
		visited[row][col+1]=false;
	}
}
int main(){
	int n = 4;
	std::vector<std::vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

	std::vector<std::vector<bool>> visited(n,std::vector<bool>(n,false));
	std::vector<std::string> result;
	std::string path="";

	if(m[0][0]==1) findPath(m,n,visited,result,path,row,col);
	for(auto index:result){
		std::cout<<index<<" ";
	}
	return 0;
}