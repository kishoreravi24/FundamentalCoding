class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<std::string> set;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val = board[i][j];
                if(val!='.'){
                    std::string row = "row"+std::to_string(i)+val;
                    std::string col = "col"+std::to_string(j)+val;
                    std::string threex = "threex"+std::to_string(i/3)+std::to_string(j/3)+val;
                    if(set.count(row)||set.count(col)||set.count(threex)){
                        return false;
                    }
                    set.insert(row);
                    set.insert(col);
                    set.insert(threex);
                }
            }
        }
        return true;
    }
};