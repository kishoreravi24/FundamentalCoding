class Solution{
public:
    long long fact(long long n){
        if(n<=1){
            return 1;
        }
        return n*fact(n-1);
    }
    vector<long long> factorial(vector<long long> a, int n) {
        std::vector<long long> res;
        for(int i=0;i<n;i++){
            res.push_back(fact(a[i]));
        }
        return res;
    }
};

//or

class Solution{
public:
    const int mod = 1e9+7;
    long long solve(long long x,std::vector<long long> &dp){
        if(x<=1){
            return 1;
        }
        if(dp[x]!=-1){
            return dp[x]%mod;
        }else{
            reurn dp[x]=(x%mod*solve(x-1,dp)%mod)%mod;
        }
    }
    std::vector<long long> factorial(std::vector<long long> a,int n){
        std::vector<long long> res;
        std::vector<long long> dp(100001,-1);
        for(int i=0;i<n;i++){
            long long z = solve(a[i],dp);
            res.push_back(z);
        }
        return res;
    }
}