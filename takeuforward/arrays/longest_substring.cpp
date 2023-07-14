class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0,j=0;
        std::unordered_set<char> set;
        for(int i=0;i<s.length();i++){
            if(set.count(s[i])==0){
                set.insert(s[i]);
                max=std::max(max,(int)set.size());
            }else{
                set.erase(s[j]);
                i--;
                j++;
            }
        }
        return max;
    }
};