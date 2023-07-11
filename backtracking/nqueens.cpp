#include<bits/stdc++.h>
#define N 4
bool safeCheck(int board[N][N],int row,int col){
	int i,j;
	//check col
	for(i=0;i<col;i++){
		if(board[row][i]){
			return false;
		}
	}

	//check row
	for(i=row;i<N;i++){
		if(board[i][col]){
			return false;
		}
	}

	//chek left side diagonal
	for(i=row,j=col;i>=0&&j>=0;i--,j--){
		if(board[i][j]){
			return false;
		}
	}

	//check right side diagonal
	for(i=row,j=col;i<N&&j>=0;i++,j--){
		if(board[i][j]){
			return false;
		}
	}

    // why right side diagonal pakkala means, first left la dana queen place pannuva then en right la check pananum
    // ipo right side la prechana vachiko namba left la vandu dan queen replace panuvom


	return true;
}
bool solveNQUtil(int board[N][N],int col){
	if(col>=N){
		return true;
	}
	for(int i=0;i<N;i++){
		if(safeCheck(board,i,col)){
			board[i][col]=1;
			if(solveNQUtil(board,col+1)){
				return true;
			}
			board[i][col]=0;
		}
	}
	return false;
}
int main(){
	int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (solveNQUtil(board, 0) == false) {
        std::cout<< "Solution does not exist";
        return false;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}