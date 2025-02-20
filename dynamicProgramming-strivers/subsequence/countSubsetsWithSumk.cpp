// Memoization

int f(int i,std::vector<int>& arr,int k,std::vector<std::vector<int>>& dp){
	// Base case
	if(k==0){
		return 1;
	}

	if(i==0){
		return (arr[0]==k);
	}

	if(dp[i][k]!=0){
		return dp[i][k];
	}

	//Pick or notPick
	int notPick = f(i-1,arr,k,dp);
	int pick = 0;
	if(arr[i]<=k) pick = f(i-1,arr,k-arr[i],dp);
	return dp[i][k]=pick+notPick;

}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	std::vector<std::vector<int>> dp(n,std::vector<int>(k+1,0));
	return f(n-1,arr,k,dp);
}


//Tabulation

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	std::vector<std::vector<int>> dp(n,std::vector<int>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0] = 1;
	}
	if(arr[0]<=k) dp[0][arr[0]] = 1;
	
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			int notPick = dp[i-1][j];
			int pick = 0;
			if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
			dp[i][j] = pick+notPick;
		}
	}
	
	return dp[n-1][k];
}

// Space optimization

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	std::vector<int> prev(k+1,0);
	prev[0] = 1;
	prev[arr[0]] = 1;
	
	for(int i=1;i<n;i++){
		std::vector<int> curr(k+1,0);
		curr[0] = 1;
		for(int j=1;j<=k;j++){
			int notPick = prev[j];
			int pick = 0;
			if(arr[i]<=j) pick = prev[j-arr[i]];
			curr[j] = pick+notPick;
		}
		prev = curr;
	}
	
	return prev[k];
}


