#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	//two pointer
	int i=0,j=0;
	std::vector<int> ans;
	while(i<m&&j<n){
		if(arr1[i]<arr2[j]){
			ans.push_back(arr1[i]);
			i++;
		}else{
			ans.push_back(arr2[j]);
			j++;
		}
	}
	while(i<m){
		ans.push_back(arr1[i]);
		i++;
	}
	while(j<n){
		ans.push_back(arr2[j]);
		j++;
	}
	return ans;
} 

//or

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.insert(nums1.begin()+m,nums2.begin(),nums2.end());
        std::sort(nums1.begin(),nums1.end());
        nums2.clear();
    }
};