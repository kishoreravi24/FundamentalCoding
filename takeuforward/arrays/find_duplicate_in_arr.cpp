class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};

or

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
    // Write your code here.
    for (int i = 0; i <arr.size(); ++i) {
        int index = std::abs(arr[i]) - 1;

        // Negate the value at its corresponding index to mark it as visited
        if (arr[index] > 0) {
            arr[index] = -arr[index];
        } else {
            return std::abs(arr[i]);
        }
    }

    // If no duplicate is found, return -1 or any appropriate value
    return -1;
}
