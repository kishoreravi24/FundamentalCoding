class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        std::unordered_map<int,int> hash_map;
        int currentSum = 0;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            currentSum += A.at(i);
            if(currentSum == 0){
                maxLength=i+1;
            }else if(hash_map.find(currentSum)!=hash_map.end()){
                maxLength=std::max(maxLength,i-hash_map[currentSum]);
            }else{
                hash_map[currentSum] = i;
            }
        }
        return maxLength;
    }
};