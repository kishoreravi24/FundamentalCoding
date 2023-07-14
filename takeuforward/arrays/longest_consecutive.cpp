class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        std::sort(nums.begin(),nums.end());
        int global_count=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]-nums[i-1]==1) count++;
            else{
                global_count=std::max(global_count,count);
                count=1;
            }
        }
        global_count=std::max(global_count,count);
        return global_count;
    }
};