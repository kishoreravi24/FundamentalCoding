class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        //3d vector
        std::vector<std::vector<std::vector<int>>> dp(r,std::vector<std::vector<int>>(c,std::vector<int>(c,-1)));

        //Base condition
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                if(j1==j2){
                    dp[r-1][j1][j2]=grid[r-1][j1];
                }else{
                    dp[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
                }
            }
        }

        //Explore all possiblities of 3x3
        for(int i=r-2;i>=0;i--){
            for(int j1=0;j1<c;j1++){
                for(int j2=0;j2<c;j2++){
                    int maxPathSum = INT_MIN;
                    int path[]={-1,0,1};
                    for(int a=0;a<3;a++){
                        for(int b=0;b<3;b++){
                            int nextj1 = j1+path[a];
                            int nextj2 = j2+path[b];
                            int value = 0;
                            if(j1==j2){
                                value=grid[i][j1];
                            }else{
                                value=grid[i][j1]+grid[i][j2];
                            }
                            if (nextj1 >= 0 && nextj1 < c && nextj2 >= 0 && nextj2 < c) {
                                value+=dp[i+1][nextj1][nextj2];
                            }else{
                                value+=INT_MIN;
                            }
                            maxPathSum = std::max(maxPathSum,value);
                        }
                    }
                    dp[i][j1][j2]=maxPathSum;
                }
            }
        }
        return dp[0][0][c-1];
    }
};