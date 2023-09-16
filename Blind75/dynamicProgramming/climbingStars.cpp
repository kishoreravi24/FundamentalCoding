class Solution {
public:
    int solve(int n,std::vector<long long> &dp){
        if(n==0||n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    int climbStairs(int n) {
        std::vector<long long> dp(n+1,-1);
        return solve(n,dp);
    }
};