class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0,value = 0;
        for(int i=0;i<accounts.size();i++){
            value = 0;
            for(int j=0;j<accounts[i].size();j++){
                value+=accounts[i][j];
            }
            if(value>=max){
                max=value;
            }
        }
        return max;
    }
};