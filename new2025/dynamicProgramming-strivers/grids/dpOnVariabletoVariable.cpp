class Solution {
public:
    int path(int i,int j,std::vector<std::vector<int>>& arr,std::vector<std::vector<int>>& dp){
        if(i==0){
            return arr[i][j];
        }

        if(j<0||j>=arr[0].size()){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = arr[i][j]+path(i-1,j,arr,dp);
        int ld = (j > 0) ? arr[i][j] + path(i - 1, j - 1, arr,dp) : INT_MAX; 
        int rd = (j < arr[0].size() - 1) ? arr[i][j] + path(i - 1, j + 1, arr,dp) : INT_MAX;
        return dp[i][j]=std::min(up,std::min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int min = INT_MAX;
        std::vector<std::vector<int>> dp(n,std::vector<int>(m,-1));
        for(int j=0;j<m;j++){
            min = std::min(min,path(n-1,j,arr,dp));
        }
        return min;
    }
};


//TAB

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dp[n-1][j] = arr[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int down = dp[i+1][j];
                int ld = (j>0)?dp[i+1][j-1]:INT_MAX;
                int rd = (j<m-1)?dp[i+1][j+1]:INT_MAX;
                dp[i][j] = arr[i][j]+std::min(down,std::min(ld,rd));
            }
        }
        
        int res = INT_MAX;
        for(int j=0;j<m;j++){
            res = std::min(res,dp[0][j]);
        }

        return res;
    }
};