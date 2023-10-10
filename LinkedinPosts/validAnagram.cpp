#include<bits/stdc++.h>
int main(){
  std::string s = "anagram";
  std::string t = "nagaram";

  if(s.size()!=t.size()){
    std::cout<<"No";
  }

  int cnt[26]={};
  for(char c:s){
    cnt[c-'a']++;
  }

  for(char c:t){
    cnt[c-'a']--;
  }

  for(int n:cnt){
    if(n){
      std::cout<<"No";
    }
  }

  std::cout<<"Yes";
  return 0;
}
