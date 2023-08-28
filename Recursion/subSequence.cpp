class Solution {
public:
    bool solve(std::string s,std::string t,std::string helper,int index){
        if(index==t.size()){
            if(helper==s){
                return true;
            }
            return false;
        }

        //Pick
        if(solve(s,t,helper+t[index],index+1)){
            return true;
        }
        //Not Pick
        if(solve(s,t,helper,index+1)){
            return true;
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
        std::string helper="";
        return solve(s,t,helper,0);
    }
};