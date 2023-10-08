#include <bits/stdc++.h>

std::vector<std::vector<int>> res;

void generateSubSets(std::vector<int> nums, std::vector<int> subsets, int startIndex) {
    res.push_back(subsets);
    for (int i = startIndex; i < nums.size(); i++) {
        subsets.push_back(nums[i]);
        generateSubSets(nums, subsets, i + 1);
        subsets.pop_back();
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::vector<int> subsets;
    generateSubSets(nums, subsets, 0);

    res.push_back({});

    for (auto index : res) {
        for (auto it : index) {
            std::cout << it << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
