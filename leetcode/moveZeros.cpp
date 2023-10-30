class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int valueToRemoved = 0;
        auto newValue = std::remove(nums.begin(),nums.end(),valueToRemoved);
        int count = std::distance(newValue,nums.end());
        nums.erase(newValue,nums.end());
        for(int i:nums){
            std::cout<<i<<" ";
        }
        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
        return;
    }
};