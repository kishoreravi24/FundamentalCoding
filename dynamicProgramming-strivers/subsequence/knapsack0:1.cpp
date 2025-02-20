class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int f(int i,int bagWt,std::vector<int>& val,std::vector<int>& wt,std::vector<std::vector<int>>& dp){
        // Base case
        if(i==0){
            return (wt[0]<=bagWt)?val[0]:0;
        }
        
        if(dp[i][bagWt]!=-1){
            return dp[i][bagWt];
        }
        
        int notTake = f(i-1,bagWt,val,wt,dp);
        int take = INT_MIN;
        if(wt[i]<=bagWt) take=val[i]+f(i-1,bagWt-wt[i],val,wt,dp);
        return dp[i][bagWt]=std::max(notTake,take);
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
    
        int n = wt.size();
        std::vector<std::vector<int>> dp(n,std::vector<int>(capacity+1,-1));
        return f(n-1,capacity,val,wt,dp);
    }
};

// Tabulation

class Solution {
public:
    int knapSack(int capacity, std::vector<int> &val, std::vector<int> &wt) {
        int n = wt.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));


        for(int i = 0; i <= capacity; i++) {
            if(i >= wt[0]) {
                dp[0][i] = val[0]; 
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int notTake = dp[i-1][j]; 
                int take = INT_MIN;
                if(wt[i] <= j) { 
                    take = val[i] + dp[i-1][j - wt[i]];
                }
                dp[i][j] = std::max(notTake, take);
            }
        }

        return dp[n-1][capacity];
    }
};

// Space optimization

class Solution{
public:
    int knapSack(int capacity, std::vector<int> &val, std::vector<int> &wt) {
        int n = wt.size();
        std::vector<int> prev(capacity+1,0),curr(capacity+1,0);

        for(int i = 0; i <= capacity; i++) {
            if(i >= wt[0]) {
                prev[i] = val[0]; 
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int notTake = prev[j]; 
                int take = INT_MIN;
                if(wt[i] <= j) { 
                    take = val[i] + prev[j - wt[i]];
                }
                curr[j] = std::max(notTake, take);
            }
            prev = curr;
        }

        return prev[capacity];
    }
};


