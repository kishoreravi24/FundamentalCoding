class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX,max=INT_MAX;
        for(auto num:nums){
            if(num<=small){
                small=num;
            }else if(num<=max){
                max=num;
            }else{
                return true;
            }
        }
        return false;
    }
};