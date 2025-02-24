class Solution {
  public:
    std::string removeDuplicateCharacters(std::string& s) {
        std::unordered_map<char, bool> hashMap;
        std::string result;

        for (int i = 0; i < s.size(); i++) {
            if (hashMap.find(s[i]) == hashMap.end()) {
                result += s[i];  
                hashMap[s[i]] = true;
            }
        }

        return result;
    }
};