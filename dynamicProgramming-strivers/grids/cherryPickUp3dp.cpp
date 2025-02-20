class Solution {
public:
    int path(int i,int j1,int j2,int r,int c,std::vector<std::vector<int>>& a){
        if(i==r-1){
            if(j1==j2){
                return a[i][j1];
            }else{
                return a[i][j1]+a[i][j2];
            }
        }

        if(j1<0||j1>=c||j2<0||j2>=c){
            return -1e8;
        }

        int res = -1e8;
        for(int al=-1;al<=1;al++){
            for(int b=-1;b<=1;b++){
                int newj1 = al+j1;
                int newj2 = b+j2;
                if(newj1>=0&&newj1<c&&newj2>=0&&newj2<c){
                    int val = 0;
                    if(j1==j2){
                        val = a[i][j1];
                    }else{
                        val = a[i][j1]+a[i][j2];
                    }
                    val+=path(i+1,newj1,newj2,r,c,a);
                    res = std::max(res,val);
                }
            }
        }
        return res;
    }
    int cherryPickup(vector<vector<int>>& a) {
     int r = a.size();
     int c = a[0].size();
     return path(0,0,c-1,r,c,a);   
    }
};

// memo

class Solution {
public:
    int path(int i,int j1,int j2,int r,int c,std::vector<std::vector<int>>& a,std::vector<std::vector<std::vector<int>>>& dp){
        if(i==r-1){
            if(j1==j2){
                return a[i][j1];
            }else{
                return a[i][j1]+a[i][j2];
            }
        }

        if(j1<0||j1>=c||j2<0||j2>=c){
            return -1e8;
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        int res = -1e8;
        for(int al=-1;al<=1;al++){
            for(int b=-1;b<=1;b++){
                int newj1 = al+j1;
                int newj2 = b+j2;
                if(newj1>=0&&newj1<c&&newj2>=0&&newj2<c){
                    int val = 0;
                    if(j1==j2){
                        val = a[i][j1];
                    }else{
                        val = a[i][j1]+a[i][j2];
                    }
                    val+=path(i+1,newj1,newj2,r,c,a,dp);
                    res = std::max(res,val);
                }
            }
        }
        return dp[i][j1][j2]=res;
    }
    int cherryPickup(vector<vector<int>>& a) {
     int r = a.size();
     int c = a[0].size();
     std::vector<std::vector<std::vector<int>>> dp(r,std::vector<std::vector<int>>(c,std::vector<int>(c,-1)));
     return path(0,0,c-1,r,c,a,dp);   
    }
};