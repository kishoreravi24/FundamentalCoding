class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int sPointer = 0;
        int tPointer = 0;

        while (sPointer < s.size() && tPointer < t.size()) {
            if (s[sPointer] == t[tPointer]) {
                sPointer++;
            }
            tPointer++;
        }

        return sPointer == s.size();
    }
};

