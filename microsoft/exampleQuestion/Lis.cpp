class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        std::vector<int> dp(n+1,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=std::max(dp[i],dp[j]+1);
                    res = std::max(res,dp[i]);
                    if(i==n-2){
                        std::cout<<nums[i]<<" "<<nums[j]<<" "<<dp[i]<<" "<<dp[j]+1<<" "<<res<<"\n";
                    }
                }
            }
        }
        return res;
    }
};