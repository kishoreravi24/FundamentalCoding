class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum=0,longest=0;
        std::unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                longest=std::max(longest,i+1);
            }else{
                if(map.find(sum)!=map.end()){
                    longest=std::max(longest,i-map[sum]);
                }else{
                    map[sum]=i;
                }
            }
        }
        return longest;
    }
};