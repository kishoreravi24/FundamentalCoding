#include<bits/stdc++.h>
int main(){
  std::string s="   fly me   to   the moon  ";
  int i = s.size()-1;
  while(i>=0 && s[i]==' '){
    i--;
  }
  int j = i;
  while(j>=0 && s[i]!=' '){
    i--;
  }
  std::cout<<j-i<<" ";
  return 0;
}
