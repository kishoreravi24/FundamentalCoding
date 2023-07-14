class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> ans;
        std::sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()||intervals[i][0]>ans.back()[1]){
                ans.push_back({intervals[i]});
            }else{
                int end = std::max(intervals[i][1],ans.back()[1]);
                ans.back()[1]=end;
            }
        }
        return ans;
    }
};

or

#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    // Write your code here.
    int n = arr.size();
    std::sort(arr.begin(),arr.end());
    std::vector<std::vector<int>> ans;
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty()&&end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=std::max(arr[j][1],end);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}