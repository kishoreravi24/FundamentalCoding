class Solution {
public:
    int f(int i,std::vector<int>& arr,int t,std::vector<std::vector<int>>& dp){

        // Base case
        if(i==0){
            return (t%arr[0]==0) ? (t/arr[0]) : 1e9;
        }

        if(dp[i][t]!=-1){
            return dp[i][t];
        }

        int notTake = f(i-1,arr,t,dp);
        int take = INT_MAX;
        if(arr[i]<=t) take = 1+f(i,arr,t-arr[i],dp);
        return dp[i][t]=std::min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(amount+1,-1));
        int res = f(n-1,coins,amount,dp);
        return (res==1e9) ? -1 : res;
    }
};

// Tabulation

class Solution{
public:

    int coinChange(vector<int>& arr, int t) {
        int n = arr.size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(t+1,1e9));

        for(int i=0;i<=t;i++){
            if(i%arr[0]==0){
                dp[0][i] = i/arr[0];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(arr[i]<=j) take = 1+dp[i][j-arr[i]];
                dp[i][j]=std::min(take,notTake);
            }
        }

        int res = dp[n-1][t];
        return (res==1e9) ? -1 : res;
    }
};


// Space optimization

class Solution{
public:
    int coinChange(vector<int>& arr,int t){
        int n = arr.size();
        std::vector<int> prev(t+1,0),curr(t+1,0);

        for(int i=0;i<=t;i++){
            if(i%arr[0]==0){
                prev[i] = i/arr[0];
            }else{
                prev[i] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                int notTake = prev[j];
                int take = INT_MAX;
                if(arr[i]<=j) take = 1+curr[j-arr[i]];
                curr[j]=std::min(take,notTake);
            }
            prev=curr;
        }

        int res = prev[t];
        return (res==1e9) ? -1 : res;

    }
};