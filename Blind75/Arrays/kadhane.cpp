class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_min_sum = nums[0];
        int curr_max_sum = nums[0];
        int max_sum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                std::swap(curr_max_sum,curr_min_sum);
            }
            curr_min_sum = std::max(nums[i],curr_min_sum*nums[i]);
            curr_max_sum = std::max(nums[i],curr_max_sum*nums[i]);
            max_sum = std::max(max_sum,curr_max_sum);
        }
        return max_sum;
    }
};