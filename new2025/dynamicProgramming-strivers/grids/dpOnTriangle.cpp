class Solution {
public:
    int path(int i,int j,int n,std::vector<std::vector<int>>& arr,std::vector<std::vector<int>>& dp){
        if(i==n-1){
            return arr[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = arr[i][j]+path(i+1,j,n,arr,dp);
        int dig = arr[i][j]+path(i+1,j+1,n,arr,dp);
        return dp[i][j]=std::min(up,dig);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(n,-1));
        return path(0,0,n,arr,dp);
    }
};

// Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[n-1].size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[n-1][j] = arr[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int up = dp[i+1][j];
                int dig = dp[i+1][j+1];
                dp[i][j] = arr[i][j]+std::min(up,dig);
            }
        }

        return dp[0][0];
    }
};