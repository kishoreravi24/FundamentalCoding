int Solution::solve(string A) {
    int n = A.size();
    int i=0;
    std::stack<char> st;
    for(auto ch:A){
        if(ch==')' && !st.empty() && st.top()=='('){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    return st.empty()?1:0;
}
