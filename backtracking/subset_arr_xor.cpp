class Solution {
public:
    std::vector<int> res;
    int calc=0;
    void backTrack(std::vector<int>& nums,std::vector<int>& subset,int start){
        if (!subset.empty()) {
            for (int index : subset) {
                res.push_back(index);
            }

            if (res.size() == 1) {
                calc += res[0];
                res.clear();
            } else {
                int x = res[0];
                for (int i = 1; i < res.size(); i++) {
                    x=x^res[i];
                }
                calc+=x;
                res.clear();
            }
        }
        
        for(int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            backTrack(nums,subset,i+1);
            subset.pop_back();
        }
        return;
    }
    int subsetXORSum(vector<int>& nums) {
        std::vector<int> subset;
        backTrack(nums,subset,0);
        return calc;
    }
};