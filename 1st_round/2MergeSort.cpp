class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		std::vector<int> res(2,-1);
		int start = 0,end = n-1;
		while(start<=end){
			int mid = start+(end-start)/2;
			if(nums[mid]<target){
				start=mid+1;
			}else{
				end=mid-1;
			}
		}
		if(start<n&&nums[start]==target){
			res[0]=start;
		}else{
			return res;
		}

		start=0;
		end=n-1;
		while(start<=end){
			int mid=start+(end-start)/2;
			if(nums[mid]>target){
				end=mid-1;
			}else{
				start=mid+1;
			}
		}
		res[1]=end;
		return res;
	}
};