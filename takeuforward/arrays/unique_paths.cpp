class Solution {
public:
    std::vector<std::vector<int>> memo;

    int dp(std::vector<std::vector<int>>& matrix, int row, int col, int m, int n){
        if(row >= 0 && row < m && col >= 0 && col < n){
            
            if(memo[row][col]!=-1){
                return memo[row][col];
            }
            
            int count=0;
            if(matrix[row][col] == 1){
                return 1;
            }
            
            //right
            count+=dp(matrix, row, col + 1, m, n);
            //bottom
            count+=dp(matrix, row + 1, col, m, n);
            
            memo[row][col]=count;
            return count;
        }
        return 0;
    }
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        matrix[m - 1][n - 1] = 1;
        memo.resize(m, std::vector<int>(n, -1));
        int result = dp(matrix, 0, 0, m, n);
        return result;
    }
};