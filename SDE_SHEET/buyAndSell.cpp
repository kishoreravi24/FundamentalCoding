#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    int buy = INT_MAX;
    int sell = 0;
    for(int i=0;i<n;i++){
        buy = std::min(buy,prices[i]);
        sell = std::max(sell,prices[i]-buy);
    }
    return sell;
}