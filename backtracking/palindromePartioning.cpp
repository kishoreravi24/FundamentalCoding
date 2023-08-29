class Solution {
public:
    bool isPalindrome(std::string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void generateSubSet(std::vector<std::vector<std::string>> &result,std::vector<std::string> &res,std::string &s,int x){
        if(x==s.size()){
            result.push_back(res);
            return;
        }
        for(int i=x;i<s.size();i++){
            if(isPalindrome(s,x,i)){
                std::string substr = s.substr(x,i-x+1);
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