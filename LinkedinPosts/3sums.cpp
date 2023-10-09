class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int low = i+1;
            int high = n-1;
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if(sum == 0){
                    res.push_back({nums[i],nums[low],nums[high]});
                }
                if(sum>=0){
                    --high;
                    while(low<high&&nums[high]==nums[high+1]){
                        --high;
                    }
                }
                if(sum<=0){
                    ++low;
                    while(low<high&&nums[low]==nums[low-1]){
                        ++low;
                    }
                }
            }
        }
        return res;
    }
};
