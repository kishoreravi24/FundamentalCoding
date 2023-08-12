#include<bits/stdc++.h>
void reverse(std::string s){
    std::string str="";
    std::vector<std::string> res;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            str+=' ';
            res.push_back(str);
            str="";
        }else{
            str+=s[i];
        }
    }
    res.push_back(str+" ");
    std::reverse(res.begin(),res.end());
    for(auto it:res){
        std::cout<<it;
    }
}
int main(){
    std::string s;
    std::getline(std::cin,s);
    reverse(s);
}