#include<bits/stdc++.h>
int reverseCheck(std::string s,std::string temp,int x,int count){
    if(x==s.length()){
        return count;
    }
    for(int i=0;i<=s.length()-x;i++){
        temp=s;
        temp.erase(i,x);
        std::string revTemp = temp;
        std::reverse(revTemp.begin(), revTemp.end());
        if(temp==revTemp&&temp.length()>1){
            return count;
        }
    }
    return reverseCheck(s,temp,x+1,count+1);
}
int main(){
    std::string s = "35577171707053";
    std::string temp = s;
    std::cout<<reverseCheck(s,temp,1,1);
}