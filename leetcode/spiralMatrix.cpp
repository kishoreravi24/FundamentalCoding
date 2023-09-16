#include<bits/stdc++.h>
class Solution{
public:
	std::vector<int> spiralMatrix(std::vector<std::vector<int>> matrix){
		std::vector<int> res;
		if(matrix.size()==0){
			return res;
		}

		int rowBegin = 0;
		int rowEnd = matrix.size()-1;
		int colBegin = 0;
		int colEnd = matrix[0].size()-1;

		while(rowBegin<=rowEnd&&colBegin<=colEnd){
			//Traverse right
			for(int i=colBegin;i<=colEnd;i++){
				res.push_back(matrix[rowBegin][i]);
			}
			rowBegin++;

			//Traverse down
			for(int i=rowBegin;i<=rowEnd;i++){
				res.push_back(matrix[i][colEnd]);
			}
			colEnd--;

			if(rowBegin<=rowEnd){
				//Travese left
				for(int i=colEnd;i>=colBegin;i--){
					res.push_back(matrix[rowEnd][i]);
				}
			}
			rowEnd--;

			if(colBegin<=colEnd){
				//Travese up
				for(int i=rowEnd;i>=rowBegin;i--){
					res.push_back(matrix[i][colBegin]);
				}
			}
			colBegin++;
		}
		return res;
	}
}