class Solution {
public:
    bool isSafe(int n, int m, int x, int y, int k){
        return x>=0 && x<n && y>=0 && y<m && k>=0;
    }
    int helper(vector<vector<int>> &grid, int x, int y, int n, int m, int k){
        if(isSafe(n,m,x,y,k)==false || grid[x][y]==-1){
            return INT_MAX/2-1;
        }
        if(x==n-1 && y==m-1){
            return 0;
        }
        if(grid[x][y]==1){
            k--;
        }
        int temp=grid[x][y];
        grid[x][y]=-1;
        int UP=helper(grid,x-1,y,n,m,k);
        int DOWN=helper(grid,x+1,y,n,m,k);
        int LEFT=helper(grid,x,y-1,n,m,k);
        int RIGHT=helper(grid,x,y+1,n,m,k);
        grid[x][y]=temp;
        if(grid[x][y]==1){
            k++;
        }
        return 1+min(min(UP,DOWN),min(LEFT,RIGHT));
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int res=helper(grid,0,0,n,m,k);
        return res==INT_MAX/2 ? -1 : res; 
    }
};

// BFS

class Solution {
public:
    int solve(std::vector<std::vector<int>> &grid,int &k){
    std::vector<std::vector<int>> visited(grid.size(),std::vector<int>(grid[0].size(),-1));
        std::queue<std::vector<int>> q;

        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int i=t[0];
            int j=t[1];
            q.pop();

            if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
                continue;
            }

            if(i==grid.size()-1&&j==grid[0].size()-1){
                return t[2];
            }

            if(grid[i][j]==1){
                if(t[3]>0){
                    t[3]--;
                }else{
                    continue;
                }
            }

            if(visited[i][j]!=-1&&visited[i][j]>=t[3]){
                continue;
            }
            visited[i][j]=t[3];

            q.push({i+1,j,t[2]+1,t[3]});
            q.push({i,j+1,t[2]+1,t[3]});
            q.push({i-1,j,t[2]+1,t[3]});
            q.push({i,j-1,t[2]+1,t[3]});
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid,k);
    }
};