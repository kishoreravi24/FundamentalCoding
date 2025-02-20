int train(int day,int lastday,std::vector<std::vector<int>>& points,std::vector<std::vector<int>>& dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0;task<3;task++){
            if(task!=lastday){
                maxi = std::max(maxi,points[day][task]);
            }
        }
        return maxi;
    }
    if(dp[day][lastday]!=-1){
        return dp[day][lastday];
    }
    int maxi = 0;
    for(int task = 0;task<3;task++){
        if(task!=lastday){
            int point = points[day][task]+train(day-1,task,points,dp);
            maxi = std::max(maxi,point);
        }
    }
    return dp[day][lastday] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    std::vector<std::vector<int>> dp(n,std::vector<int>(4,-1));
    return train(n-1,3,points,dp);
}


// Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    std::vector<std::vector<int>> dp(n,std::vector<int>(4,0));
    dp[0][0] = std::max(points[0][1],points[0][2]);
    dp[0][1] = std::max(points[0][0],points[0][2]);
    dp[0][2] = std::max(points[0][0],points[0][1]);
    dp[0][3] = std::max(points[0][0],std::max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point = dp[day][task]+dp[day-1][task];
                    dp[day][last] = std::max(point,dp[day][last]);
                }
            }
        }
    }
    return dp[n-1][3];
    
}