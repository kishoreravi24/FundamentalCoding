class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        std::priority_queue<std::pair<int,int>> pq;
        std::vector<int> ans;
        for(int i=0;i<k;i++){
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<arr.size();i++){
            pq.push({arr[i],i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};