class Solution {
public:
    int f(int n){
        if(n==0||n==1){
            return 1;
        }
        int left = f(n-1);
        int right = f(n-2);
        return left+right;
    }
    int climbStairs(int n) {
        return f(n);
    }
};

// Tabulation
class Solution{
public:
    int climbStairs(int n){
        std::vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Space optimization
class Solution{
public:
    int climbStairs(int n){
        int prev = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
            int curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
