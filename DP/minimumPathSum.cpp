class Solution {
public:
    int solve(std::vector<std::vector<int>> grid,int i,int j,std::vector<std::vector<int>> &dp){
        //Base condition
        if(i==0&&j==0){
            return grid[0][0];
        }
        //Boundary condition
        if(i<0||j<0){
            return 1e9;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = grid[i][j]+solve(grid,i-1,j,dp);
        int down = grid[i][j]+solve(grid,i,j-1,dp);
        dp[i][j] = std::min(up,down);
        return std::min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};

// or

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //Tabulation
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    dp[i][j]=grid[0][0];
                }else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0){
                        up = grid[i][j]+dp[i-1][j];
                    }
                    if(j>0){
                        left = grid[i][j]+dp[i][j-1];
                    }
                    dp[i][j]=std::min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};