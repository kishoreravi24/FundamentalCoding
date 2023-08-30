#include<bits/stdc++.h>
void rotateClockWise90(std::vector<std::vector<int>> &matrix){
	// Transpose
	for(int i=0;i<matrix.size();i++){
		for(int j=i+1;j<matrix[0].size();j++){
			std::swap(matrix[i][j],matrix[j][i]);
		}
	}

	for(int i=0;i<matrix.size();i++){
		std::reverse(matrix[i].begin(),matrix[i].end());
	}
	return;
}
int main(){
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    rotateClockWise90(matrix);
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
    return 0;
}