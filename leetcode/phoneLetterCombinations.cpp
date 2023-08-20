class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> result={};
        if(digits==""){
            return result;
        }
        result.push_back("");
        std::vector<std::string> pad = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        for(auto digit:digits){
            std::vector<std::string> temp;
            for(auto value:pad[digit-'0']){
                for(auto res:result){
                    temp.push_back(res+value);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};