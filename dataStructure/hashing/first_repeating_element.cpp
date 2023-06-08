int findFirstRepeatingElement(int arr[], int n) {
    unordered_set<int> encountered;

    int firstRepeatingIndex = -1;

    for (int i = 0; i < n; i++) {
        if (encountered.find(arr[i]) != encountered.end()) {
            firstRepeatingIndex = i;
            break;
        }
        encountered.insert(arr[i]);
    }

    return firstRepeatingIndex;
}