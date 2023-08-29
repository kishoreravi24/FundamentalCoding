#include <bits/stdc++.h>

void makeZero(std::vector<std::vector<int>> &matrix,int row,int col){
	for(int i=0;i<matrix[0].size();i++){
		matrix[row][i]=0;
	}

	for(int i=0;i<matrix.size();i++){
		matrix[i][col] = 0;
	}
	return;
}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int m = matrix.size();
	int n = matrix[0].size();
	std::vector<std::pair<int,int>> gettingPairs;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0){
				gettingPairs.push_back({i,j});
			}
		}
	}
	for(auto index:gettingPairs){
		makeZero(matrix,index.first,index.second);
	}
	return;
}