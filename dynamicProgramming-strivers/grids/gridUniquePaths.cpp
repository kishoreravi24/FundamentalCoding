class Solution {
public:
    int path(int i,int j,std::vector<std::vector<int>>& dp){
        // Base case
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // Paths
        int up = path(i-1,j,dp);
        int left = path(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,-1));
        return path(m-1,n-1,dp);
    }
};


// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,-1));
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

//or

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;  // Start point
                } else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i - 1][j];  // Coming from above
                    if (j > 0) left = dp[i][j - 1];  // Coming from left
                    dp[i][j] = up + left; 
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

  

