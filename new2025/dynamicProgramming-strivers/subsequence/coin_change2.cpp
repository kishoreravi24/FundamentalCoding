#include<vector>

long f(int i, int* arr, int t, std::vector<std::vector<long>>& dp) {
    if (i == 0) {
        return (t % arr[0] == 0);
    }

    if (dp[i][t] != -1) {
        return dp[i][t];
    }

    long notTake = f(i - 1, arr, t, dp);
    long take = 0;
    if (arr[i] <= t) {
        take = f(i, arr, t - arr[i], dp);
    }
    return dp[i][t] = take + notTake;
}

long countWaysToMakeChange(int* denominations, int n, int value) {
    std::vector<std::vector<long>> dp(n, std::vector<long>(value + 1, -1));
    return f(n - 1, denominations, value, dp);
}


// Tabulation

long countWaysToMakeChange(int *arr, int n, int value)
{
    std::vector<std::vector<long>> dp(n, std::vector<long>(value + 1, 0));

    // Base case
    for(int i=0;i<=value;i++){
        if(value%arr[0]==0){
            dp[0][i]=1;
        }
    }

    for(int i=1;i<n;i++){
        for(int t=0;t<=value;t++){
            long notTake = dp[i - 1][t];
            long take = 0;
            if (arr[i] <= t) {
                take = dp[i][t - arr[i]];
            }
            dp[i][t] = take + notTake;
        }
    }

    return dp[n-1][value];
}


// Space optimization

long countWaysToMakeChange(int *arr, int n, int value)
{
    std::vector<long> prev(value+1,0);
    std::vector<long> curr(value+1,0);

    // Base case
    for(int i=0;i<=value;i++){
        if(value%arr[0]==0){
            prev[i]=1;
        }
    }

    for(int i=1;i<n;i++){
        for(int t=0;t<=value;t++){
            long notTake = prev[t];
            long take = 0;
            if (arr[i] <= t) {
                take = curr[t - arr[i]];
            }
            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];
}