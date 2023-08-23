class Solution {
public:
/*
formula : sell - buy i.e buy = 1 day 2 and sell = 5 day 3
profit = 5-1 = 4, so prices[i] is (-) i.e -prices[i]

buy:
    Take: -prices[index]+market(index+1,0) , bcz hold one stock
    not-take: 0+market(index+1,1)
sell:
    Take: prices[index]+market(index+1,1) // i sold so i can buy
    no-take: 0+market(index+1,0) // still holding

*/
    long market(int index,int buy,std::vector<int> prices,std::vector<std::vector<int>> dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        long maxProfit = 0;
        if(buy){
            int takeBuy = -prices[index]+market(index+1,0,prices,dp);
            int notTakeBuy = 0+market(index+1,1,prices,dp);
            maxProfit = std::max(takeBuy,notTakeBuy);
        }else{
            int takeSell = prices[index]+market(index+1,1,prices,dp);
            int notTakeSell = 0+market(index+1,0,prices,dp);
            maxProfit = std::max(takeSell,notTakeSell);
        }
        dp[index][buy]=maxProfit;
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        std::vector<std::vector<int>> dp(n,std::vector<int>(2,-1));
        return market(0,buy,prices,dp);
    }
};


//or


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (size_t p = 1; p < prices.size(); ++p) 
        ret += max(prices[p] - prices[p - 1], 0);    
        return ret;
    }
};