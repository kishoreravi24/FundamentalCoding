class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        std::string s = "";
        int count = 0;
        while(s.size()<b.size()){
            s+=a;
            count++;
        }
        if(s.find(b)!=std::string::npos){
            return count;
        }
        s+=a;
        count++;
        if(s.find(b)!=std::string::npos){
            return count;
        }
        return -1;
    }
};
