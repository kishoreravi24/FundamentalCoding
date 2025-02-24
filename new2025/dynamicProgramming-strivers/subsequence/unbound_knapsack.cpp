#include<bits/stdc++.h>

int f(int i,int bagWt,std::vector<int>& val,std::vector<int>& wt,std::vector<std::vector<int>>& dp){
    if(i==0){
        return ((int)bagWt/wt[0])*val[0];
    }

    if(dp[i][bagWt]!=-1){
        return dp[i][bagWt];
    }

    int notTake = 0+f(i-1,bagWt,val,wt,dp);
    int take = INT_MIN;
    if(wt[i]<=bagWt) take = val[i]+f(i,bagWt-wt[i],val,wt,dp);
    return dp[i][bagWt]=std::max(take,notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    std::vector<std::vector<int>> dp(n,std::vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

// Tabulation


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    std::vector<std::vector<int>> dp(n,std::vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        if(wt[0]<=i){
            dp[0][i] = ((int)i/wt[0])*val[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake = 0+dp[i-1][j];
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i]+dp[i][j-wt[i]];
            dp[i][j]=std::max(take,notTake);
        }
    }

    return dp[n-1][w];
}

// Space optimization


int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    std::vector<int> prev(w+1,0),curr(w+1,0);

    for(int i=0;i<=w;i++){
        if(wt[0]<=i){
            prev[i] = ((int)i/wt[0])*val[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake = 0+prev[j];
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i]+curr[j-wt[i]];
            curr[j]=std::max(take,notTake);
        }
        prev = curr;
    }

    return prev[w];
}
