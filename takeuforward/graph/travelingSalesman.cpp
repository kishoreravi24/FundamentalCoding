#include<bits/stdc++.h>
class Solution{
    int solve(std::vector<std::vector<int>> &cost,std::unordered_set<int> &cities,int &start){
        int n = cost.size();
        int minPath = INT_MAX;
        for(int i=0;i<n;i++){
            if(cities.count(i)){
                cities.erase(cities.find(i)); //visited

                if(cities.empty()){
                    minPath = std::min(minPath,cost[start][i]+cost[i][0]); //source cost + current node cost
                }else{
                    minPath = std::min(minPath,cost[start][i]+solve(cost,cities,i));
                }
                cities.insert(i);
            }
        }
        return minPath;
    }
    int total_cost(vector<vector<int>>cost){
        std::unordered_set<int> cities;
        int n = cost.size();
        for(int i=1;i<n;i++){
            cities.insert(i);
        }
        int result = solve(cost,cities,0);
        if(result == INT_MAX){
            return 0;
        }
        return result;
    }
};