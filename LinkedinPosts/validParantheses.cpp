class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(char c:s){
            if(c=='{'||c=='('||c=='['){
                st.push(c);
            }else{
                if(st.empty()||
                (c==')'&&st.top()!='(')||
                (c=='}'&&st.top()!='{')||
                (c==']'&&st.top()!='[')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
