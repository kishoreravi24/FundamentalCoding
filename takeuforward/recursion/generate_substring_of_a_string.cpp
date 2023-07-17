class Solution {
public:
    void generateSubSet(std::vector<std::vector<std::string>> &result,std::vector<std::string> &res,std::string &s,int x){
        result.push_back(res);
        for(int i=x;i<s.size();i++){
            std::string substr = s.substr(x,i-x+1);
            //without duplicates
            if(std::find(res.begin(),res.end(),substr)==res.end()){
                res.push_back(substr);
                generateSubSet(result,res,s,i+1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> res;
        generateSubSet(result,res,s,0);
        return result;
    }
};