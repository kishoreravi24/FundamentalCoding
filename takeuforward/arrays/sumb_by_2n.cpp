std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // stores element-index pairs
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if the complement exists in the map and its index is not the same as the current index
        if (numMap.count(complement) && numMap[complement] != i) {
            return {numMap[complement], i}; // return indices of the two elements
        }
        
        numMap[nums[i]] = i; // store current element and its index
    }
    
    return {}; // return an empty vector if no solution is found
}