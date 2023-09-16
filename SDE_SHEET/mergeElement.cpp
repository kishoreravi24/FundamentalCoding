int f(int i,int j,std::vector<int> &A,std::vector<int> &pre,std::vector<std::vector<int>> &dp){
    if(i==j){
        return 0;
    }
    if(i+1==j){
        return A[i]+A[j];
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        ans = std::min(ans,pre[j+1]-pre[i]+f(i,k,A,pre,dp)+f(k+1,j,A,pre,dp));
    }
    return dp[i][j]=ans;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    std::vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+A[i-1];
    }
    std::vector<std::vector<int>> dp(n,std::vector<int>(n,-1));
    return f(0,n-1,A,pre,dp);
}
