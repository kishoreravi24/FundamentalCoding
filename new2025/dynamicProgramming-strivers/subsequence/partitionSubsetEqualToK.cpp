#include<bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    std::vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool notPick = prev[j];
            bool pick = false;
            if(arr[i]<=j) pick = prev[j-arr[i]];
            curr[j]=pick|notPick; 
        }
        prev = curr;
    }
    return prev[k];
    // return f(n-1,arr,k,dp);
}
bool canParition(std::vector<int>& arr,int n){
	int totSum = 0;
	for(int i=0;i<n;i++){
		totSum+= arr[i];
	}
	if(totSum%2) return false;
	int target = totSum/2;

	return subsetSumToK(n-1,arr,target);
}