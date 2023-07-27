class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(std::vector<std::pair<int,int>> pairs,int start,int bagWt,std::vector<std::vector<int>> &dp){
        if(start==0){
            if(pairs[0].first<=bagWt){
                return pairs[0].second;
            }else{
                return 0;
            }
        }
        
        if(dp[start][bagWt]!=-1){
            return dp[start][bagWt];
        }
        
        int w = pairs[start].first;
        int v = pairs[start].second;
        
        int notTake = 0+solve(pairs,start-1,bagWt,dp);
        int take = INT_MIN;
        
        if(w<=bagWt){
            //pick
            take = v+solve(pairs,start-1,bagWt-w,dp);
        }
        
        return dp[start][bagWt]=std::max(notTake,take);
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        std::vector<std::pair<int,int>> pairs;
        int bagWt=W;
       
        for(int i=0;i<n;i++){
           pairs.push_back({wt[i],val[i]});
        }
        std::sort(pairs.begin(),pairs.end());
        std::vector<std::vector<int>> dp(n,std::vector<int>(W+1,-1));
        return solve(pairs,n-1,bagWt,dp);
    }
};