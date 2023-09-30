class Solution {
public:
    int countSegments(string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> wordArr;
        while(ss >> word){
            wordArr.push_back(word);
        }
        return wordArr.size();
    }
};