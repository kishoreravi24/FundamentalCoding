class Solution {
public:
    void generateSubSet(std::vector<std::vector<int>> &result,std::vector<int> &res,std::vector<int> &candidates,int x,int target){
        if(target<0){
            return;
        }else if(target==0){
            result.push_back(res);
            return;
        }
        for(int i=x;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i>x&&candidates[i]==candidates[i-1]) continue;
            res.push_back(candidates[i]);
            generateSubSet(result,res,candidates,i+1,target-candidates[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> res;
        std::sort(candidates.begin(),candidates.end());
        generateSubSet(result,res,candidates,0,target);
        return result;
    }
};