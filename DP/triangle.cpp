class Solution {
public:
    int solve(std::vector<std::vector<int>> triangle,int m,int i,int j,std::vector<std::vector<int>> &dp){
        //Base condition
        if(i==m-1){
            return triangle[m-1][j];
        }

        // //Boundary condition
        // if(i>m-1||j>n-1){
        //     return 1e9;
        // }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down = triangle[i][j]+solve(triangle,m,i+1,j,dp);
        int diagonal = triangle[i][j]+solve(triangle,m,i+1,j+1,dp);
        return dp[i][j]=std::min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(m,-1));
        return solve(triangle,m,0,0,dp);
    }
};