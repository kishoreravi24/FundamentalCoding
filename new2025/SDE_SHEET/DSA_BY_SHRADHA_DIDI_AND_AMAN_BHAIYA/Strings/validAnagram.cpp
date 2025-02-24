class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        if(s!=t){
            return false;
        }
        return true;
    }
};

// or

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        std::vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }

        return true;
    }
};

// or

class Solution:
    def isAnagram(self,s:str,t:str) -> bool:
        counter_s = Counter(s)
        counter_t = Counter(t)

        return counter_s == counter_t


