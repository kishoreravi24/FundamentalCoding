#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    // Sort intervals based on the start values
    std::vector<std::vector<int>> res;
    std::sort(intervals.begin(),intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
        if(res.empty()||intervals[i][0]>res.back()[1]){
            res.push_back({intervals[i]});
        }else{
            int secondInterval = std::max(intervals[i][1],res.back()[1]);
            res.back()[1] = secondInterval;
        }
    }
    return res;
}
