class Solution {
public:
    bool checkBoard(std::vector<std::vector<char>> &board,int row,int col,int index,std::string word){
        if(index==word.size()){
            return true;
        }

        //bounday condition
        if(row<0||row==board.size()||col<0||col==board[0].size()||board[row][col]!=word[index]){
            return false;
        }

        //visited
        char temp = board[row][col];
        board[row][col]='*';

        bool res = checkBoard(board,row,col-1,index+1,word)||
                   checkBoard(board,row,col+1,index+1,word)||
                   checkBoard(board,row-1,col,index+1,word)||
                   checkBoard(board,row+1,col,index+1,word);
        
        board[row][col]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(checkBoard(board,i,j,0,word)){
                    return true;
                }
            }
        }

        return false;
    }
};