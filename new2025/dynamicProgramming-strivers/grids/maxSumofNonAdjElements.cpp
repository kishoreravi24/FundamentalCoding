// House robber

#include<bits/stdc++.h>
int subs(int ind,std::vector<int>& arr){
	if(ind == 0){
		return arr[ind];
	}
	if(ind<0){
		return 0;
	}

	int pick = arr[ind]+subs(ind-2,arr);
	int notPick = 0+subs(ind-1,arr);
	return std::max(pick,notPick);
}
int main(){
	std::vector<int> arr = {1,2,4};
	int n = 3;
	std::cout<<subs(n,arr)<<std::endl;
	return 0;
}

// Memoization

#include<bits/stdc++.h>
int subs(int ind,std::vector<int>& arr,std::vector<int>& ds){
	if(ind == 0){
		return arr[ind];
	}
	if(ind<0){
		return 0;
	}
	if(ds[ind]!=-1){
		return ds[ind];
	}
	int pick = arr[ind]+subs(ind-2,arr,ds);
	int notPick = 0+subs(ind-1,arr,ds);
	return ds[ind]=std::max(pick,notPick);
}
int main(){
	std::vector<int> arr = {1,2,4};
	int n = 3;
	std::vector<int> ds(n,-1);
	std::cout<<subs(n-1,arr,ds)<<std::endl;
	return 0;
}

// Tabulation

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &arr){
    // Write your code here.
    int n = arr.size();
    std::vector<int> ds(n,-1);
    ds[0] = arr[0];
    for(int i=1;i<n;i++){
        int take = arr[i];
        if(i>1){
            take+=ds[i-2];
        }
        int nottake = 0+ds[i-1];
        ds[i] = std::max(take,nottake);
    }
    return ds[n-1];
}

// Space Optimization

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &arr){
    // Write your code here.
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1;i<arr.size();i++){
        int take = arr[i];
        if(i>1){
            take+=prev2;
        }
        int nottake = 0+prev;
        int curr = std::max(take,nottake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}