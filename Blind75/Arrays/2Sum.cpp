#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        int newNum = 0;
        for(int i=0;i<nums.size();i++){
        	newNum = target-nums[i];
        	if(hash.count(newNum)>0){
        		return {hash[newNum],i};
        	}else{
        		hash[nums[i]]=i;
        	}
        }
        return {};
    }
};