class Solution {
public:
    void checkDfs(std::vector<std::vector<char>> &grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||i==m||j<0||j==n||grid[i][j]=='0'){ //boundary condition
            return;
        }
        grid[i][j]='0'; //visited
        //left
        checkDfs(grid,i,j-1);
        //right
        checkDfs(grid,i,j+1);
        //up
        checkDfs(grid,i-1,j);
        //down
        checkDfs(grid,i+1,j);

    }
    int numIslands(vector<vector<char>>& grid) {
        int numOfIsland = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    numOfIsland++;
                    checkDfs(grid,i,j);
                }
            }
        }
        return numOfIsland;
    }
};