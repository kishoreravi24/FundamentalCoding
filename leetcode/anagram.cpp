class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};


//or


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        std::unordered_map<char,int> hashMap;
        for(int i=0;i<s.size();i++){
            hashMap[s[i]]++;
            hashMap[t[i]]--;
        }
        for(auto index:hashMap){
            if(index.second){
                return false;
            }
        }
        return true;
    }
};

