class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        std::string result;
        for(int i=0;i<s.size();i++){
            if(i==0||s[i]!=s[i-1]){
                result+=s[i];
            }
        }
        return result;
    }
};