#include<bits/stdc++.h>
class Solution{
  public:
    std::string longestCommonPrefix(std::vector<std::string> s){
      int len = s[0].size();
      for(int i=1;i<strs.size()&&len;i++){
        int j=0,end = std::min(len,(int)s[i].size());
        while(j<end&&s[0][j]==s[i][j]){
          j++;
        }
        len = j;
      }
      return s[0].substr(0,len);
    }
};
