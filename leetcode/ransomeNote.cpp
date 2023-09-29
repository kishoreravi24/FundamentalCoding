class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char,int> charFreq;

        for(char c:magazine){
            charFreq[c]++;
        }

        for(char c:ransomNote){
            if(charFreq.find(c)!=charFreq.end()&&charFreq[c]>0){
                charFreq[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};