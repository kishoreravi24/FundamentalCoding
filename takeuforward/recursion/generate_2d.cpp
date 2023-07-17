#include<bits/stdc++.h>
class Solution{
	void generateSubSet(std::vector<std::vector<int>> &result,std::vector<int> &res,std::vector<int> nums,int x){
		result.push_back(res);
		for(int i=x;i<nums.size();i++){
			if(i>x&&nums[i]==nums[i-1]) continue;
			res.push_back(nums[i]);
			generateSubSet(result,res,nums,i+1);
			res.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		std::vector<std::vector<int>> result;
		std::vector<int> res;
		generateSubSet(result,res,nums,0);
		return result;
	}
};