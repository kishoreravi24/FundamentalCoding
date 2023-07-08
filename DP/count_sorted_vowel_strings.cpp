class Solution {
public:
    int t(vector<vector<int>>&dp,int n,int i){
        if(i==0){
            dp[n][i]=0;
            return dp[n][i];
        }
        if(n==1){
            dp[n][i]=i;
            return dp[n][i];
        }
        if(dp[n][i]!=-1)return dp[n][i];
        dp[n][i] = t(dp,n-1,i) + t(dp,n,i-1);
        return dp[n][i];
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5+1,-1));
        t(dp,n,5);
        return dp[n][5];
    }
};