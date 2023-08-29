#include<bits/stdc++.h>

void solve(std::vector<int> &nums, std::vector<int> &permutation, int index, std::vector<int> &res) {
    if (index == nums.size()) {
        if (nums > permutation) {
            res.assign(nums.begin(), nums.end());
        }
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        std::swap(nums[index], nums[i]);
        solve(nums, permutation, index + 1, res);
        std::swap(nums[index], nums[i]);
    }
    return;
}

int main() {
    std::vector<int> permutation = {1, 2, 3};
    int n;
    std::cin >> n;
    
    std::vector<int> res;
    std::vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    
    solve(nums, permutation, 0, res);
    
    if (!res.empty()) {
        for (auto index : res) {
            std::cout << index << " ";
        }
    } else {
        std::cout << "No next permutation found." << std::endl;
    }
    
    std::cout << "\n";
    return 0;
}
