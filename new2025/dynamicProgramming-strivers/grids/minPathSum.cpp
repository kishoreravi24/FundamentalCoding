class Solution {
public:
    int path(int i,int j,std::vector<std::vector<int>>& grid,std::vector<std::vector<int>>& dp){
        if(i==0&&j==0){
            return grid[i][j];
        }

        if(i<0||j<0){
            return 1e9;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = grid[i][j]+path(i-1,j,grid,dp);
        int left = grid[i][j]+path(i,j-1,grid,dp);
        return dp[i][j]=std::min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1,-1));
        return path(n-1,m-1,grid,dp);
    }
};

// Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<std::vector<int>> dp(n,std::vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }

        for(int j=1;j<m;j++){
           dp[0][j] = dp[0][j-1]+grid[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int up = grid[i][j]+dp[i-1][j];
                int left = grid[i][j]+dp[i][j-1];
                dp[i][j]=std::min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
};