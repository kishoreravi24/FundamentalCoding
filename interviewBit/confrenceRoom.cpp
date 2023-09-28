int Solution::solve(vector<vector<int> > &intervals) {
    std::sort(intervals.begin(),intervals.end(),[](const std::vector<int>& a,const std::vector<int>& b){
        return a[0] < b[0];
    });
    
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    pq.push(intervals[0][1]);
    
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]>=pq.top()){
            pq.pop();
        }
        pq.push(intervals[i][1]);
    }
    return pq.size();
}
