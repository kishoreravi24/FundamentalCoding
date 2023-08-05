class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int curr_sum=0;
        int res=INT_MIN;
        int size = nums.size();
        for(int i=0;i<size;i++){
            curr_sum+=nums[i];
            if(curr_sum<nums[i]){
                curr_sum=nums[i];
            }
            res=std::max(curr_sum,res);
        }
        return res;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans;
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                ans.push_back(sum);
            }
        }
        std::sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};

//kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum=nums[0];
        int max_sum=nums[0];

        for(int i=1;i<n;i++){
            curr_sum = std::max(nums[i],curr_sum+nums[i]);
            max_sum = std::max(curr_sum,max_sum);
        }
        return max_sum;
    }
};