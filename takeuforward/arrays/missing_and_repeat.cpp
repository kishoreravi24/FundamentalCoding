#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    int missing = 0;
    for (int i = 1; i <= n; i++) {
        auto it = std::find(arr.begin(), arr.end(), i);
        if (it == arr.end()) {
            missing = i;
            break;  // Exit the loop once the missing number is found
        }
    }

    std::unordered_set<int> seen;
    std::vector<int> duplicates;
    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i]) > 0) {
            duplicates.push_back(arr[i]);
        } else {
            seen.insert(arr[i]);
        }
    }

    return std::make_pair(missing, duplicates[0]);
}
