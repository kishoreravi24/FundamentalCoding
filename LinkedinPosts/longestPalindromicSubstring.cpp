#include<bits/stdc++.h>
class Solution{
  public:
    bool isPalindrome(std::string s,int start,int end){
      while(start<end){
        if(s[start]!=s[end]){
          return false;
        }
        start++;
        end--;
      }
      return true;
    }
    std::string lps(std::string s,int start,int end){
      if(start>=end){
        return s.substr(start,1);
      }

      if(isPalindrome(s,start,end)){
        return s.substr(start,end-start+1);
      }

      std::string left = lps(s,start,end-1);
      std::string right = lps(s,start+1,end);

      return (left.length() > right.length()) ? left:right;
    }
    std::string longestPalindromicSubstring(std::string s){
      int n = s.size();
      if(n<=1){
        return s;
      }
      return lps(s,0,n-1);
    }
}
