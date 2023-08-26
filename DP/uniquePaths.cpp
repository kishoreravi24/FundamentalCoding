#include<bits/stdc++.h>
int solve(std::vector<std::vector<int>> matrix,int i,int j,std::vector<std::vector<int>> &visited){
	if(i==0&&j==0){
		return 1;
	}
	if(i<0||j<0){
		return 0;
	}
	if(visited[i][j]!=-1){
		return visited[i][j];
	}

	int up = solve(matrix,i-1,j,visited);
	int down = solve(matrix,i,j-1,visited);
	visited[i][j] = up+down;
	return up+down;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	std::vector<std::vector<int>> matrix(m,std::vector<int>(n,1));
	matrix[0][0]=0;
	std::vector<std::vector<int>> visited(m,std::vector<int>(n,-1));
	return solve(matrix,m-1,n-1,visited);
}
int main(){
	int m,n;
	std::cin>>m>>n;
	std::cout<<uniquePaths(m,n);
}

// Tabulation

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                }else{
                    int up = 0;
                    int down = 0;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        down = dp[i][j-1];
                    }
                    dp[i][j]=up+down;
                }
            }
        }
    return dp[m-1][n-1];
    }
};