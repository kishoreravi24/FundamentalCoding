class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        for(int i=0;i<nums.size()-3;i++){
            int complement = target-nums[i];
            for(int j=i+1;j<nums.size()-2;j++){
                std::unordered_map<int,int> map;
                int subcomplement=complement-nums[j];
                for(int k=j+1;k<nums.size();k++){
                    int subsubcomplement = subcomplement-nums[k];
                    if(map.count(subsubcomplement)){
                        res.push_back({nums[i],nums[j],nums[k],nums[map[subsubcomplement]]});
                    }
                    map[nums[k]]=k;
                }
            }
        }
        res.erase(std::unique(res.begin(),res.end()),res.end());
        return res;
    }
};