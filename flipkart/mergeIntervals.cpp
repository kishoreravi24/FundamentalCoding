class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //    std::sort(intervals.begin(),intervals.end(),[](const std::vector<int> &v1,const std::vector<int> &v2){
    //        return v1[1]<v2[1];
    //    });
        std::sort(intervals.begin(),intervals.end());
       std::vector<std::vector<int>> ans;
       int start=intervals[0][0],end=intervals[0][1];
       std::cout<<start<<" "<<end<<"\n";
       for(int i=1;i<intervals.size();i++){
           if(end>=intervals[i][0]){
               if(intervals[i][1]>=end){
                   end=intervals[i][1];
               }
           }else{
               ans.push_back({start,end}); //start,end
               start = intervals[i][0];
               end = intervals[i][1];
           }
       }
       ans.push_back({start,end}); //start,end
       return ans;
    }
};