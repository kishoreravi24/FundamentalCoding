class Solution {
public:
    int path(int i,int j,std::vector<std::vector<int>>& arr,std::vector<std::vector<int>>& dp){
        // Base case
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        if(i>=0&&j>=0&&arr[i][j]==1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //Paths
        int up = path(i-1,j,arr,dp);
        int left = path(i,j-1,arr,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        if (arr[0][0] == 1 || arr[m - 1][n - 1] == 1) {
            return 0;
        }
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,-1));
        return path(m-1,n-1,arr,dp);
    }
};

// Tabulation

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        if (arr[0][0] == 1 || arr[m - 1][n - 1] == 1) {
            return 0;
        }
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,-1)); 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                }else if(arr[i][j]==1){
                    dp[i][j]=0;
                }else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        } 
        return dp[m-1][n-1];
    }
};

// Space optimize


