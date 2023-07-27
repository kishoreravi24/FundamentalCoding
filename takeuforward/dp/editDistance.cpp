class Solution {
public:
    int minD(int i,int j,std::string s1,std::string s2,std::vector<std::vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            dp[i][j]=0+minD(i-1,j-1,s1,s2,dp);
        }else{
            dp[i][j]= 1+std::min(minD(i,j-1,s1,s2,dp),std::min(minD(i-1,j,s1,s2,dp),minD(i-1,j-1,s1,s2,dp)));
        }
        return dp[i][j];
    }
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,-1));
        return minD(m-1,n-1,s1,s2,dp);
    }
};