 class Solution {
public:
    int majorityElement(int arr[], int size) {
        std::map<int, int> hashMap;

        for (int i = 0; i < size; i++) {
            hashMap[arr[i]]++;
        }

        for (const auto &index : hashMap) {
            int count = index.second;
            if (count > size / 2) {
                return index.first;
            }
        }

        return -1;
    }
};