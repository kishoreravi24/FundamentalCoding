#include<bits/stdc++.h>
class Solution{
public:
	void solve(std::vector<int> &candidates,int index,int target,std::vector<int> &helper,std::vector<std::vector<int>> &result){
		//Boundary condition
		if(target<0){
			return;
		}
		//Base condition
		if(target==0){
			result.push_back(helper);
		}

		//skip duplicates dont try at the result.push_back
		//Try to skip at the insertion of helper 
		for(int i=index;i<candidates.size();i++){
			if(candidates[i]>target){ // checking the value is index value is enough for the target
				break;
			}
			if(i>index && candidates[i]==candidates[i-1]){ // checking duplicates
				continue;
			}

			helper.push_back(candidates[i]);
			solve(candidates,i+1,target-candidates[i],helper,result);
			helper.pop_back();
		}
		return;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::vector<int> helper;
		std::vector<std::vector<int>> result;
		std::sort(candidates.begin(),candidates.end());
		solve(candidates,0,target,helper,result);
		return result;
	}

};