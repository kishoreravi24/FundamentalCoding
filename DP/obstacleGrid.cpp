class Solution {
public:
    int solve(std::vector<std::vector<int>> obstacleGrid,int i,int j,std::vector<std::vector<int>> &visited){
        //Obstacle condition
        if(i>=0&&j>=0&&obstacleGrid[i][j]==1){
            return 0;
        }
        //Base condition
        if(i==0&&j==0){
            return 1;
        }
        //Boundary condition
        if(i<0||j<0){
            return 0;
        }
        //Visited check
        if(visited[i][j]!=-1){
            return visited[i][j];
        }
        
        //calculate count
        int up = solve(obstacleGrid,i-1,j,visited);
        int left = solve(obstacleGrid,i,j-1,visited);
        visited[i][j] = up+left;
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //Dp
        std::vector<std::vector<int>> visited(m,std::vector<int>(n,-1));

        return solve(obstacleGrid,m-1,n-1,visited);
    }
};

//or

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Tabulation
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>=0&&j>=0&&obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else if(i==0&&j==0){
                    dp[i][j]=1;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left = dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};