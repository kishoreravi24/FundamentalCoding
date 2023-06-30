class Solution {
public:
    int findGcd(int str1,int str2){
        int min=std::min(str1,str2);
        while(min!=0){
            if(str1%min==0&&str2%min==0){
                return min;
            }
            min--;
        }
        return 0;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2==str2+str1){
            return str1.substr(0,findGcd(str1.length(),str2.length()));
        }else{
            return "";
        }
    }
};