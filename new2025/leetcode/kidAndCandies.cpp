class Solution {
public:
    bool checker(std::vector<int>& candies, int a){
        for(auto& val:candies){
            if(a<val){
                return false;
            }
        }
        return true;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::vector<bool> res;
        for(int i=0;i<candies.size();i++){
            if(checker(candies,candies[i]+extraCandies)){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};

// optimize

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(),candies.end());
        std::vector<bool> res;
        res.reserve(candies.size());
        for(int candy:candies){
            res.push_back(candy+extraCandies >= maxCandy);
        }
        return res;
    }
};