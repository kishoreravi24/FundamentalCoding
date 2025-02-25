class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string res = "";
        int m = word1.size();
        int n = word2.size();
        res.reserve(m+n);
        int i=0,j=0;
        while(i<m||j<n){
            if(i<m) res+=word1[i++];
            if(j<n) res+=word2[j++];
        }
        return res;
    }
};