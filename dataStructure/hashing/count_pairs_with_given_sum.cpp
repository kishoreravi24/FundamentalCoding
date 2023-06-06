int countPairsWithSum(int arr[], int n, int sum) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = sum - arr[i];

        // Check if the complement exists in the map
        if (freq.find(complement) != freq.end()) {
            count += freq[complement];
        }

        // Increase the frequency of the current element
        freq[arr[i]]++;
    }

    return count;
}