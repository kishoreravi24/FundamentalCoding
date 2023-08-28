#include<bits/stdc++.h>
void subSequence(std::string s,std::string &helper,std::vector<std::string> &res,int index){
    if(index==s.size()){
        res.push_back(helper);
        return;
    }

    //Include the char
    subSequence(s,helper+s[index],res,index+1);
    //Exclude the char
    subSequence(s,helper,res,index+1);
    return;

}
int main(){
    std::string s,t;
    std::cin>>s>>t;
    std::string helper = "";
    std::vector<std::string> res;
    subSequence(s,t,helper,res,0);
    return;
}