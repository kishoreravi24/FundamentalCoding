class Solution {
  public:
    // Function to find the number of islands.
    void visitingTheIsland(std::vector<std::vector<char>>& grid,int i,int j,int rows,int columns){
        //boundary check
        if(i<0||i>=rows||j<0||j>=columns||grid[i][j]!='1'){
            return;
        }
        //visitedIsland marking as 2 
        grid[i][j]='2';
        
        //checking top of the island is water or another island
        visitingTheIsland(grid,i-1,j,rows,columns);
        //checking bottom of the island is water or another island
        visitingTheIsland(grid,i+1,j,rows,columns);
        //checking left of the island is water or another island
        visitingTheIsland(grid,i,j-1,rows,columns);
        //checking right of the island is water or another island
        visitingTheIsland(grid,i,j+1,rows,columns);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        // Get rows and cloumns
        int rows = grid.size();
        if(rows==0){
            return 0;
        }
        int columns = grid[0].size();
        int visitedIsland=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]=='1'){
                    visitingTheIsland(grid,i,j,rows,columns);
                    visitedIsland+=1;
                }
            }
        }
        return visitedIsland;
    }
};