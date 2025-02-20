class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return std::max(getMax(nums,0,nums.size()-2),getMax(nums,1,nums.size()-1));
    }
private:
    int getMax(std::vector<int>& nums,int start,int end){
        int prev = 0;
        int prev2 = 0;
        for(int i=start;i<=end;i++){
            int temp = std::max(prev,prev2+nums[i]);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};