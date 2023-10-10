class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char,int> hashMap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for(int i=0;i<s.size();i++){
            if(hashMap[s[i]]<hashMap[s[i+1]]){
                res-=hashMap[s[i]];
            }else{
                res+=hashMap[s[i]];
            }
        }
        return res;
    }
};
