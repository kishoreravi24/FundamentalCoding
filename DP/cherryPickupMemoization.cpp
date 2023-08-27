class Solution {
public:
    int solve(std::vector<std::vector<int>> grid,int r,int c,int i,int j1,int j2,std::vector<std::vector<std::vector<int>>> &dp){
        //Boundary condition
        if(j1<0||j1>=c||j2<0||j2>=c){
            return INT_MIN;
        }

        //Base condition
        if(i==r-1){
            if(j1==j2){
                return grid[i][j2];
            }else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        //robot1 have 3 combination x robot2 have 3 combination
        int maxPathSum = INT_MIN;
        int path[]={-1,0,1};
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                int nextj1 = j1+path[a];
                int nextj2 = j2+path[b];
                int value = 0;
                if(j1==j2){
                    value=grid[i][j1];
                }else{
                    value=grid[i][j1]+grid[i][j2];
                }
                value+=solve(grid,r,c,i+1,nextj1,nextj2,dp);
                maxPathSum = std::max(maxPathSum,value);
            }
        }
        return dp[i][j1][j2]=maxPathSum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        //3d vector
        std::vector<std::vector<std::vector<int>>> dp(r,std::vector<std::vector<int>>(c,std::vector<int>(c,-1)));
        // indexes i,j1,j2 i.e j1 robot1 , j2 robot2
        return solve(grid,r,c,0,0,c-1,dp);
    }
};