class Solution {
public:
    void solve(std::vector<std::vector<int>>& matrix,std::vector<std::pair<int,int>> notice,int rows,int cols){
        for(auto index:notice){
            int i=index.first;
            int j=index.second;
            
            for(int k=0;k<rows;k++){
                matrix[k][j]=0;
            }
            
            for(int k=0;k<cols;k++){
                matrix[i][k]=0;
            }
        }
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<std::pair<int,int>> notice;
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    notice.push_back(std::make_pair(i,j));
                }
            }
        }
        
        solve(matrix,notice,rows,cols);
        return;
    }
};