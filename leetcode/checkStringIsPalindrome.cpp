class Solution {
public:
    bool isPalindrome(string s) {
        std::string stringPath = "";

        //remove alpha numeric and convert to lower case
        for(char c:s){
            if(std::isalnum(c)){
                stringPath.push_back(std::tolower(c));
            }
        }

        std::string reverseString = stringPath;
        std::reverse(reverseString.begin(),reverseString.end());

        if(reverseString == stringPath){
            return true;
        }

        return false;
    }
};