class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = candies.size();
        std::vector<bool> result(size,false);
        int maxCandy = 0;

        for(int i=0;i<size;i++){
            maxCandy = std::max(maxCandy,candies[i]);
        }

        for(int i=0;i<size;i++){
            if(extraCandies+candies[i]>=maxCandy){
                result[i]=true;
            }else{
                result[i]=false;
            }
        }
        return result;
    }
};