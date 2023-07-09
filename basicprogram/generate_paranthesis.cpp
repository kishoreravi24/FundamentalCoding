class Solution {
public:
    void solve(std::string op,int open,int close,std::vector<std::string>& ans){
        if(open==0&&close==0){
            ans.push_back(op);
            return;
        }else if(open==close){
            std::string s1=op;
            s1.push_back('(');
            solve(s1,open-1,close,ans);
        }else if(open==0){
            std::string s1=op;
            s1.push_back(')');
            solve(s1,open,close-1,ans);
        }else if(close==0){
            std::string s1=op;
            s1.push_back('(');
            solve(s1,open-1,close,ans);
        }else{
            std::string s1=op;
            std::string s2=op;
            s1.push_back('(');
            s2.push_back(')');
            solve(s1,open-1,close,ans);
            solve(s2,open,close-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        std::string op="";
        int open=n;
        int close=n;
        std::vector<std::string> ans;
        solve(op,open,close,ans);
        return ans;
    }
};