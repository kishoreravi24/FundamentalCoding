class Solution{
public:
    void coinChecker(int coins[],std::vector<int>& ans,int x,int N){
        if(N==0){
            return;
        }
        for(int i=x-1;i>=0;i--){
            if(N>=coins[i]){
                int val = std::abs(N-coins[i]);
                ans.push_back(coins[i]);
                return coinChecker(coins,ans,x,val);
            }
        }
    }
    vector<int> minPartition(int N)
    {
        // code here
        int coins[10]={1,2,5,10,20,50,100,200,500,2000};
        std::vector<int> ans;
        coinChecker(coins,ans,10,N);
        return ans;
    }
};