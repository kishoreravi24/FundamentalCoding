class Solution {
public:
    string reverseVowels(string s) {
        static std::unordered_set<char> hash = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        std::stack<char> st;

        for(int i=0;i<s.length();i++){
            if(hash.find(s[i])!=hash.end()){
                st.push(s[i]);
                s[i]='$';
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='$'){
                s[i]=st.top();
                st.pop();
            }
        }

        return s;
    }
};