class Solution {
public:
    double slideWindow(std::vector<int> nums,int k,int size){
        int currSum=0;
        double ans;
        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }
        ans=currSum/(double)k;
        double maxAns = ans;
        for(int i=k;i<size;i++){
            currSum+=nums[i]-nums[i-k];
            ans=currSum/(double)k;
            if(ans>maxAns){
                maxAns=ans;
            }
        }
        return maxAns;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double res = slideWindow(nums,k,nums.size());
        return res;
    }
};