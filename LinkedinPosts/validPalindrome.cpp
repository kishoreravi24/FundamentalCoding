#include<bits/stdc++.h>
int main(){
  std::string s="A man, a plan, a canal: Panama";
  std::string convertedString = "";
  for(char c:s){
    if(std::isalnum(c)){
      convertedString.push_back(std::tolower(c));
    }
  }
  std::string reverse = s;
  std::reverse(reverse.begin(),reverse.end());
  if(reverse == convertedString){
    std::cout<<"Valid";
  }

  std::cout<<"No";
  return 0;
}
