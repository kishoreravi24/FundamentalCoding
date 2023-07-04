#include<bits/stdc++.h>
int findBin(int x,int a[]){
	int i=0;
	while(x!=0){
		a[i++]=x%2;
		x/=2;
	}
}
int findones(int a[]){
	int count=0;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]==1){
			count++;
		}
	}
	return count;
}
int main(){
	int n=5,a[32];
	std::vector<int> result;
	for(int i=0;i<=n;i++){
		findBin(i,a);
		int res = findones(a);
		result.push_back(res);
	}
	for(auto index:result){
		std::cout<<index<<" ";
	}
	return 0;
}

or


class Solution {
    public int[] countBits(int n) {
        int res[] = new int[n + 1]; 
        
        for(int i = 0; i <= n; i++){ 
            res[i] = solve(i, res);
        }
        return res;
    }
    public int solve(int n, int memo[]){

        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(memo[n] != 0) return memo[n]; // if memo of n answer is already available we will re-use it & not go further for calculation
        // but if you are coming for the first time then, store that value in memo
        if(n % 2 == 0) {
            memo[n] = solve(n / 2, memo);
            return solve(n / 2, memo);
        }
        else {
            memo[n] = 1 + solve(n / 2, memo);
            return 1 + solve(n / 2, memo);
        } 
    }
}