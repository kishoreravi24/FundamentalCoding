class Solution {
public:
std::vector<int> majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    std::vector<int> res;

    int threshold = nums.size() / 3;

    for (int num : nums) {
        countMap[num]++;
        if (countMap[num] > threshold && std::find(res.begin(), res.end(), num) == res.end()) {
            res.push_back(num);
        }
    }

    return res;
}
};