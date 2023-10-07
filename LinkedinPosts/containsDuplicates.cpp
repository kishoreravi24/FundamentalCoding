#include<bits/stdc++.h>
int main(){
	std::vector<int> nums = {1,2,3,1};
	int n = nums.size();
	std::vector<int> cnt(n,0);
	for(int n:nums){
		cnt[n]++;
	}

	for(int i:cnt){
		if(i>1){
			return 1;
		}
	}
	return 0;
}

//or

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> hashSet;
        for(int n:nums){
            if(hashSet.count(n)>0){
                return true;
            }
            hashSet.insert(n);
        }
        return false;
    }
};