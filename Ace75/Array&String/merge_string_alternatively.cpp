class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size = std::max(word1.length(),word2.length());
        std::string s3;
        for(int i=0;i<size;i++){
            if(i<word1.length()){
                s3+=word1[i];
            }
            if(i<word2.length()){
                s3+=word2[i];
            }
        }
        return s3;
    }
};