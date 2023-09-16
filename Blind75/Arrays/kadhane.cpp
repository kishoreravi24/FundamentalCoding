class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max_product = nums[0];
        int curr_min_product = nums[0];
        int max_product = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(curr_max_product, curr_min_product);
            }
            
            curr_max_product = max(nums[i], curr_max_product * nums[i]);
            curr_min_product = min(nums[i], curr_min_product * nums[i]);
            
            max_product = max(max_product, curr_max_product);
        }
        
        return max_product;
    }
};
