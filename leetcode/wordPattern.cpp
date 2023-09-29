class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> pattern2;

        while (ss >> word) {
            pattern2.push_back(word);
        }

        std::unordered_map<char, std::string> map1;
        std::unordered_map<std::string, char> map2;
        
        if (pattern.size() != pattern2.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            if (map1.find(pattern[i]) != map1.end() && map1[pattern[i]] != pattern2[i]) {
                return false;
            }
            if (map2.find(pattern2[i]) != map2.end() && map2[pattern2[i]] != pattern[i]) {
                return false;
            }
            map1[pattern[i]] = pattern2[i];
            map2[pattern2[i]] = pattern[i];
        }
        return true;
    }
};
