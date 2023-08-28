class Solution {
public:
    void printSubSet(std::vector<int> nums,std::vector<int> helper,std::vector<std::vector<int>> &res, int index){
        if(index==nums.size()){
            res.push_back(helper);
            return;
        }
        helper.push_back(nums[index]);
        printSubSet(nums,helper,res,index+1);
        helper.pop_back();
        printSubSet(nums,helper,res,index+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> helper;
        std::vector<std::vector<int>> res;
        printSubSet(nums,helper,res,0);
        return res;
    }
};