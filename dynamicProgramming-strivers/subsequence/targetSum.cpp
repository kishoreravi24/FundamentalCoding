class Solution {
public:
	int f(std::vector<int>& nums,int t){
		int n = nums.size();
		std::vector<int> prev(t+1,0);
        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (nums[0]<=t&&nums[0]!=0){
            prev[nums[0]] = 1;
        }

		for(int i=1;i<n;i++){
			std::vector<int> curr(t+1,0);
			for(int j=0;j<=t;j++){
				int notTake = prev[j];
				int take = false;
				if(nums[i]<=j) take = prev[j-nums[i]];
				curr[j] = take+notTake;
			}
			prev=curr;
		}
		return prev[t];
	}
    int findTargetSumWays(vector<int>& nums, int target) {
  		int totSum = 0;
        int n = nums.size();

  		for(int i=0;i<n;i++){
  			totSum+=nums[i];
  		}
  		if(totSum-target<0||(totSum-target)%2!=0) return false;

  		return f(nums,(totSum-target)/2);
    }
};