bool boardSafe(int board[][9],int row,int col,int k){
    for(int i=0;i<9;i++){
        if(board[i][col]==k){
            return false;
        }
        if(board[row][i]==k){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==k){
            return false;
        }
    }
    return true;
}

bool solve(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(boardSafe(board,i,j,k)){
                        board[i][j]=k;
                        if(solve(board)==true){
                            return true;
                        }else{
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int board[][9]) {
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Don't print output and return output as specified in the question
    */
    solve(board);
}