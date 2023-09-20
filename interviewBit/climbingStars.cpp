int solve(int A,std::vector<int> dp){
    if(A==0||A==1){
        return 1;
    }
    if(dp[A]!=-1){
        return dp[A];
    }
    return solve(A-1,dp)+solve(A-2,dp);
}
int Solution::climbStairs(int A) {
    std::vector<int> dp(A+1,-1);
    return solve(A,dp);
}
