#include <bits/stdc++.h> 
bool f(int i,std::vector<int>& arr,int k,std::vector<std::vector<int>>& dp){
    if(k==0) return true;
    if(i==0) return (arr[0]==k);

    if(dp[i][k]!=-1){
        return dp[i][k];
    }

    bool notPick = f(i-1,arr,k,dp);
    bool pick = false;
    if(arr[i]<=k) pick = f(i-1,arr,k-arr[i],dp);
    return dp[i][k]=pick|notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    std::vector<std::vector<int>> dp(n,std::vector<int>(k+1,-1));
    return f(n-1,arr,k,dp);
}

// Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    std::vector<std::vector<bool>> dp(n,std::vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notPick = dp[i-1][j];
            bool pick = false;
            if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
            dp[i][j]=pick|notPick; 
        }
    }
    return dp[n-1][k];
    // return f(n-1,arr,k,dp);
}


// space optimization

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    std::vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notPick = prev[j];
            bool pick = false;
            if(arr[i]<=j) pick = prev[j-arr[i]];
            curr[j]=pick|notPick; 
        }
        prev = curr;
    }
    return prev[k];
    // return f(n-1,arr,k,dp);
}
