class Solution {
public:
    long long int mod = pow(10,9)+7;
    std::unordered_map<std::string,long long int> hash;
    int solve(int steps,int xpos,int arrLen){
        std::string key = std::to_string(steps)+","+std::to_string(xpos);
        auto it = hash.find(key);
        if(it!=hash.end()){
            return it->second;
        }

        //Base condition for characther move
        if(xpos<0||xpos>=arrLen){
            return 0;
        }

        //Base condition for steps
        if(steps<0){
            return 0;
        }

        //combine both
        if(steps==0){
            if(xpos==0){
                return 1;
            }else{
                return 0;
            }
        }

        long long int ans = 0;
        ans+=solve(steps-1,xpos-1,arrLen);
        ans+=solve(steps-1,xpos,arrLen);
        ans+=solve(steps-1,xpos+1,arrLen);

        ans%=mod;
        hash.insert({key,ans});
        return ans;
    }
    int numWays(int steps, int arrLen) {
        int xpos = 0;
        return solve(steps,xpos,arrLen);
    }
};