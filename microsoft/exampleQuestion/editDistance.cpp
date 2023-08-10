class Solution {
public:
    int solve(std::string s1,std::string s2,int m,int n,std::vector<std::vector<int>> &dp){
        if(m<0){
            return n+1;
        }
        if(n<0){
            return m+1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(s1[m]==s2[n]){
            return dp[m][n]=0+solve(s1,s2,m-1,n-1,dp);
        }else{
            return dp[m][n]=1+std::min(solve(s1,s2,m,n-1,dp),std::min(solve(s1,s2,m-1,n,dp),solve(s1,s2,m-1,n-1,dp)));
        }
        return dp[m][n];
    }
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,-1));
        return solve(s1,s2,m-1,n-1,dp);
    }
};