class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        //  Write your code here.
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j]+dp[i-1][j];
                int ld = matrix[i][j];
                if(j-1>=0){
                    ld+=dp[i-1][j-1];
                }else{
                    ld+=1e9;
                }
                int rd = matrix[i][j];
                if(j+1<n){
                    rd+=dp[i-1][j+1];
                }else{
                    rd+=1e9;
                }
                dp[i][j]=std::min(up,std::min(ld,rd));
            }
        }
        
        int maxPathSum = 1e9;
        for(int i=0;i<n;i++){
            maxPathSum=std::min(maxPathSum,dp[m-1][i]);
        }
        return maxPathSum;
    }
};