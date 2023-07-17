class Solution {
public:
    void generateSubSet(vector<vector<int>>& result, vector<int>& res, vector<int>& candidates, int x, int target) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(res);
            return;
        }
        for (int i = x; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            res.push_back(candidates[i]);
            generateSubSet(result, res, candidates, i, target - candidates[i]);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        generateSubSet(result, res, candidates, 0, target);
        return result;
    }
};
