class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string,std::vector<std::string>> set;
        for(auto str:strs){
            std::string temp = str;
            std::sort(temp.begin(),temp.end());
            set[temp].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for(auto x:set){
            ans.push_back(x.second);
        }

        return ans;
    }
};