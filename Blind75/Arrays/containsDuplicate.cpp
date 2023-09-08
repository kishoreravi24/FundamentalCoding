class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

//or

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()){
                return true;
            }else{
                hash.insert(nums[i]);
            }
        }
        return false;
    }
};