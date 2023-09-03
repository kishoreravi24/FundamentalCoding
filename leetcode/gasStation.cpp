class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //Sum of Gas
        int gasSum = 0;
        for(auto index:gas){
            gasSum+=index;
        }

        //Sum of Cost
        int gasCost = 0;
        for(auto index:cost){
            gasCost+=index;
        }

        if(gasSum<gasCost){
            return -1;
        }
        int total = 0;
        int pos = 0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total = 0;
                pos = i+1;
            }
        }
        return pos;
    }
};