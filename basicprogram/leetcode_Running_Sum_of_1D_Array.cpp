class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> new_num(nums.size());

        new_num.at(0) = nums.at(0);

        for(std::vector<int>::size_type i=1;i!=nums.size(); i++){
            new_num[i] = nums[i]+new_num[i-1];
        }
        return new_num;
    }
};