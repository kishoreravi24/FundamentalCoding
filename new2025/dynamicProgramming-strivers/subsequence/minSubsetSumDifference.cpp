int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totSum = 0;
	for(int i=0;i<n;i++){
		totSum+=arr[i];
	}

	int k = totSum;
	std::vector<std::vector<bool>> dp(n,std::vector<bool>(k+1,false));
	//Base case
	for(int i=0;i<n;i++){
		dp[i][0] = true;
	}
	if(arr[0]<=k) dp[0][arr[0]] = true;
	
	//Work
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			bool notPick = dp[i-1][j];
			bool pick = false;
			if(arr[i]<=j){
				pick = dp[i-1][j-arr[i]];
			}
			dp[i][j] = pick||notPick;
		}
	}

	int mini = 1e9;
	for(int s1=0;s1<=totSum/2;s1++){
		if(dp[n-1][s1]==true){
			mini = std::min(mini,abs((totSum-s1)-s1));
		}
	}

	return mini;
}
