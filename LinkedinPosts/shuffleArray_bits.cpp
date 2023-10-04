class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = nums.size();
        for(int i=n;i<size;i++){
            nums[i] = nums[i]<<10;
            nums[i] = nums[i]|nums[i-n];
        }

        int j=0;
        for(int i=n;i<size;i++){
            nums[j]=nums[i]&1023;
            nums[j+1]=nums[i]>>10;
            j+=2;
        }
        return nums;
    }
};
