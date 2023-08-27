#include <bits/stdc++.h> 

int solve(std::vector<std::vector<int>> matrix,int i,int j,std::vector<std::vector<int>> &visited){
    //Boundary condition
    if(j<0||j>=matrix[0].size()){
        return -1e8;
    }
    
    //Base condition
    if(i==0){
        return matrix[0][j];
    }

    if(visited[i][j]!=-1){
        return visited[i][j];
    }

    int up = matrix[i][j]+solve(matrix,i-1,j,visited);
    int ld = matrix[i][j]+solve(matrix,i-1,j-1,visited);
    int rd = matrix[i][j]+solve(matrix,i-1,j+1,visited);
    return visited[i][j]=std::max(up,std::max(ld,rd));

}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> visited(m,std::vector<int>(n,-1));
    int maxPathSum = -1e8;
    for(int i=0;i<n;i++){
        maxPathSum = std::max(maxPathSum,solve(matrix,m-1,i,visited));
    }
    return maxPathSum;
}

// or

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
    for(int i=0;i<n;i++) dp[0][i]=matrix[0][i];
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int up = matrix[i][j]+dp[i-1][j];
            int ld = matrix[i][j];
            if(j-1>=0){
                ld+=dp[i-1][j-1];
            }else{
                ld+=-1e8;
            }
            int rd = matrix[i][j];
            if(j+1<n){
                rd+=dp[i-1][j+1];
            }else{
                rd+=-1e8;
            }
            dp[i][j]=std::max(up,std::max(ld,rd));
        }
    }
    
    int maxPathSum = -1e8;
    for(int i=0;i<n;i++){
        maxPathSum=std::max(maxPathSum,dp[m-1][i]);
    }
    return maxPathSum;
}