std::vector<int> sortA1ByA2(std::vector<int> A1, int N, std::vector<int> A2, int M) {
    std::map<int, int> countMap;
    std::vector<int> result;

    for (int i = 0; i < N; i++) {
        countMap[A1[i]]++;
    }

    for (int i = 0; i < M; i++) {
        if (countMap.find(A2[i]) != countMap.end()) {
            int count = countMap[A2[i]];
            result.insert(result.end(), count, A2[i]);
        }
        countMap.erase(A2[i]);
    }

    for (const auto& pair : countMap) {
        int count = pair.second;
        result.insert(result.end(), count, pair.first);
    }

    return result;
}