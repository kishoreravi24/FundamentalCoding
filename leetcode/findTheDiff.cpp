class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char,int> hashMap;
        for(char c:s){
            hashMap[c]++;
        }
        for(char c:t){
            if(hashMap[c]>0){
                hashMap[c]--;
            }else{
                return c;
            }
        }
        return t[0];
    }
};