int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int minDiff = INT_MAX;

    while (i < A.size() && j < B.size() && k < C.size()) {
        int maxVal = A[i];
        maxVal = std::max(maxVal, B[j]);
        maxVal = std::max(maxVal, C[k]);

        int minVal = A[i];
        minVal = std::min(minVal, B[j]);
        minVal = std::min(minVal, C[k]);

        minDiff = std::min(minDiff, maxVal - minVal);

        if (A[i] == minVal) {
            i++;
        } else if (B[j] == minVal) {
            j++;
        } else {
            k++;
        }
    }

    return minDiff;
}
