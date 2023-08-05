class Solution {
public:
    string longestPalindrome(string s) {
        std::string res="";
        int n = s.size();
        std::vector<std::pair<int,std::string>> result;
        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                for(int k=i;k<=j;k++){
                    res+=s[k];
                }
                std::string res1 = res;
                std::reverse(res1.begin(),res1.end());
                if(res==res1){
                    result.push_back({res.size(),res});
                }
                res.clear();
            }
        }
        std::sort(result.begin(),result.end());
        return result[result.size()-1].second;
    }
};